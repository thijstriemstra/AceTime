#ifndef CLOCK_CLOCK_H
#define CLOCK_CLOCK_H

#include <AceTime.h>
#include <ace_time/hw/CrcEeprom.h>
#include <ace_time/common/DateStrings.h>
#include "RenderingInfo.h"
#include "StoredInfo.h"
#include "Presenter.h"

using namespace ace_time;
using namespace ace_time::common;
using namespace ace_time::provider;

/**
 * Class responsible for rendering the RenderingInfo to the indicated display.
 * Different subclasses output to different types of displays. In an MVC
 * architecture, this would be the Controller. The Model would be the various
 * member variables in this class. The View layer are the various Presenter
 * classes.
 */
class Clock {
  public:
    static const uint16_t kStoredInfoEepromAddress = 0;

    static const int16_t kDefaultOffsetMinutes = -8*60; // UTC-08:00

    /**
     * Constructor.
     * @param timeKeeper source of the current time
     * @param crcEeprom stores objects into the EEPROM with CRC
     * @param presenter renders the date and time info to the screen
     */
    Clock(TimeKeeper& timeKeeper, hw::CrcEeprom& crcEeprom,
            Presenter& presenter):
        mTimeKeeper(timeKeeper),
        mCrcEeprom(crcEeprom),
        mPresenter(presenter) {}

    void setup() {
      // Restore from EEPROM to retrieve time zone.
      StoredInfo storedInfo;
      bool isValid = mCrcEeprom.readWithCrc(kStoredInfoEepromAddress,
          &storedInfo, sizeof(StoredInfo));
      if (isValid) {
        mCurrentZoneSpec = ManualZoneSpec(
            UtcOffset::forMinutes(storedInfo.offsetMinutes),
            UtcOffset::forHour(1));
        mCurrentZoneSpec.isDst(storedInfo.isDst);
        mHourMode = storedInfo.hourMode;
      } else {
        mCurrentZoneSpec = ManualZoneSpec(
            UtcOffset::forMinutes(kDefaultOffsetMinutes),
            UtcOffset::forHour(1));
        mHourMode = StoredInfo::kTwentyFour;
      }

      // Retrieve current time from TimeKeeper.
      acetime_t nowSeconds = mTimeKeeper.getNow();

      // Set the current date time using the mTimeZone.
      mCurrentDateTime = ZonedDateTime::forEpochSeconds(
          nowSeconds, TimeZone(&mCurrentZoneSpec));
    }

    /**
     * This should be called every 0.1s to support blinking mode and to avoid
     * noticeable drift against the RTC which has a 1 second resolution.
     */
    void update() {
      if (mMode == MODE_UNKNOWN) return;
      if (mIsPreparingToSleep) return;
      updateDateTime();
      updateBlinkState();
      updateRenderingInfo();
      mPresenter.display();
    }

    virtual void modeButtonPress() = 0;

    virtual void modeButtonLongPress() = 0;

    virtual void changeButtonPress() = 0;

    virtual void changeButtonRelease() = 0;

    virtual void changeButtonRepeatPress() = 0;

  protected:
    void updateDateTime() {
      mCurrentDateTime = ZonedDateTime::forEpochSeconds(
          mTimeKeeper.getNow(), TimeZone(&mCurrentZoneSpec));

      // If in CHANGE mode, and the 'second' field has not been cleared,
      // update the mChangingDateTime.second field with the current second.
      switch (mMode) {
        case MODE_CHANGE_YEAR:
        case MODE_CHANGE_MONTH:
        case MODE_CHANGE_DAY:
        case MODE_CHANGE_HOUR:
        case MODE_CHANGE_MINUTE:
        case MODE_CHANGE_SECOND:
          if (!mSecondFieldCleared) {
            mChangingDateTime.second(mCurrentDateTime.second());
          }
          break;
      }
    }

    /** Update the blinkShowState. */
    void updateBlinkState () {
      uint16_t now = millis();
      uint16_t duration = now - mBlinkCycleStartMillis;
      if (duration < 500) {
        mBlinkShowState = true;
      } else if (duration < 1000) {
        mBlinkShowState = false;
      } else {
        mBlinkCycleStartMillis = now;
      }
    }

    void updateRenderingInfo() {
      mPresenter.setMode(mMode);
      mPresenter.setSuppressBlink(mSuppressBlink);
      mPresenter.setBlinkShowState(mBlinkShowState);

      switch (mMode) {
        case MODE_DATE_TIME:
#if DISPLAY_TYPE == DISPLAY_TYPE_LED || DISPLAY_TYPE == DISPLAY_TYPE_OLED
        case MODE_HOUR_MINUTE:
        case MODE_MINUTE_SECOND:
        case MODE_YEAR:
        case MODE_MONTH:
        case MODE_DAY:
#endif
        case MODE_WEEKDAY:
        case MODE_TIME_ZONE:
          mPresenter.setDateTime(mCurrentDateTime);
          mPresenter.setTimeZone(mCurrentZoneSpec);
          mPresenter.setHourMode(mHourMode);
          break;

        case MODE_CHANGE_YEAR:
        case MODE_CHANGE_MONTH:
        case MODE_CHANGE_DAY:
        case MODE_CHANGE_HOUR:
        case MODE_CHANGE_MINUTE:
        case MODE_CHANGE_SECOND:
        case MODE_CHANGE_TIME_ZONE_HOUR:
        case MODE_CHANGE_TIME_ZONE_MINUTE:
        case MODE_CHANGE_TIME_ZONE_DST:
        case MODE_CHANGE_HOUR_MODE:
          mPresenter.setDateTime(mChangingDateTime);
          mPresenter.setTimeZone(mChangingZoneSpec);
          mPresenter.setHourMode(mHourMode);
          break;
      }
    }

    /** Save the current UTC dateTime to the RTC. */
    void saveDateTime() {
      mTimeKeeper.setNow(mChangingDateTime.toEpochSeconds());
    }

    void saveTimeZone() {
      mCurrentZoneSpec = mChangingZoneSpec;
      mCurrentDateTime = mCurrentDateTime.convertToTimeZone(
          TimeZone(&mCurrentZoneSpec));
      preserveInfo();
    }

    void preserveInfo() {
      StoredInfo storedInfo;
      storedInfo.timeZoneType = mCurrentZoneSpec.getType();
      storedInfo.offsetMinutes = mCurrentZoneSpec.stdOffset().toMinutes();
      storedInfo.isDst = mCurrentZoneSpec.isDst();
      storedInfo.hourMode = mHourMode;

      mCrcEeprom.writeWithCrc(kStoredInfoEepromAddress, &storedInfo,
          sizeof(StoredInfo));
    }

  protected:
    TimeKeeper& mTimeKeeper;
    hw::CrcEeprom& mCrcEeprom;
    Presenter& mPresenter;

    uint8_t mMode = MODE_UNKNOWN; // current mode

    ManualZoneSpec mCurrentZoneSpec;
    ZonedDateTime mCurrentDateTime; // DateTime from the TimeKeeper

    ManualZoneSpec mChangingZoneSpec;;
    ZonedDateTime mChangingDateTime; // DateTime set by user in "Change" modes

    bool mSecondFieldCleared;
    bool mSuppressBlink; // true if blinking should be suppressed
    uint8_t mHourMode = 0; // 12/24 mode

    bool mBlinkShowState = true; // true means actually show
    uint16_t mBlinkCycleStartMillis = 0; // millis since blink cycle start
    bool mIsPreparingToSleep = false;
};

#endif
