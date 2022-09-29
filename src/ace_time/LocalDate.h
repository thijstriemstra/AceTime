/*
 * MIT License
 * Copyright (c) 2018 Brian T. Park
 */

#ifndef ACE_TIME_LOCAL_DATE_H
#define ACE_TIME_LOCAL_DATE_H

#include <stdint.h>
#include <string.h> // strlen()
#include <Arduino.h>
#include <AceCommon.h> // printPad2To()
#include "common/common.h"
#include "common/DateStrings.h" // DateStrings
#include "internal/EpochConverterJulian.h"
#include "internal/EpochConverterHinnant.h"

class Print;

namespace ace_time {

/**
 * The date (year, month, day) representing the date without regards to time
 * zone.
 *
 * Normally, the range of the year field is [1,9999]. Occasionally, the year 0
 * is used to indicate -Infinity, with the month and day fields ignored. And the
 * year 10000 is used to indicate +Infinity, with the month and day fields
 * ignored. The value of INT16_MIN (-32768) is used to indicate an error
 * condition.
 *
 * The `toEpochDays()` and `fromEpochDays()` provides conversions of the (year,
 * month, day) tuple to the number of days since the "epoch". The default epoch
 * year is 2000, which makes the epoch date-time be 2000-01-01T00:00:00.
 *
 * The epoch year can be changed using the static `localEpochYear()` method.
 * This is useful for dates larger than 2068-01-19T03:14:07, which is the
 * largest date-time that can be represented using an `int32_t` type to hold the
 * number of seconds since the epoch. For example, calling
 * `localEpochYear(2100)` will set the epoch to be 2100-01-01T00:00:00, so
 * that dates from 2031-12-13 20:45:52Z to 2168-01-20T03:14:07 can be captured.
 *
 * The dayOfWeek (1=Monday, 7=Sunday, per ISO 8601) is calculated from the date
 * fields.
 *
 * Parts of this class were inspired by the java.time.LocalDate class of Java
 * 11
 * (https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/time/LocalDate.html).
 *
 * @tparam T_CONVERTER class responsible for providing the
 *    T_CONVERTER::toEpochDays() and T_CONVERTER::fromEpochDays() functions
 */
template <typename T_CONVERTER>
class LocalDateTemplate {
  public:
    /** Epoch year used by the internal epoch converters. Probably year 2000. */
    static const int16_t kBaseEpochYear = T_CONVERTER::kEpochConverterBaseYear;

    /**
     * Number of days from Unix epoch (1970-01-01 00:00:00 UTC) to
     * the AceTime base epoch (2000-01-01 00:00:00 UTC).
     */
    static const int32_t kDaysToBaseEpochFromUnixEpoch = 10957;

    /**
     * Number of seconds from Unix epoch (1970-01-01 00:00:00 UTC) to
     * the AceTime base epoch (2000-01-01 00:00:00 UTC).
     */
    static const int32_t kSecondsToBaseEpochFromUnixEpoch =
        kDaysToBaseEpochFromUnixEpoch * 86400;

    /**
     * Sentinel year which indicates an error condition or sometimes a year
     * that 'does not exist'.
     */
    static const int16_t kInvalidYear = INT16_MIN;

    /**
     * Sentinel year which represents the smallest year, effectively -Infinity.
     */
    static const int16_t kMinYear = 0;

    /**
     * Sentinel year which represents the largest year, effectively +Infinity.
     */
    static const int16_t kMaxYear = 10000;

    /** Sentinel epochDays which indicates an error. */
    static const int32_t kInvalidEpochDays = INT32_MIN;

    /** Sentinel epochSeconds which indicates an error. */
    static const int32_t kInvalidEpochSeconds = INT32_MIN;

    /** Sentinel epochSeconds64 which indicates an error. */
    static const int64_t kInvalidEpochSeconds64 = INT64_MIN;

    /**
     * Minimum valid epochSeconds. The smallest int32, `INT32_MIN`, is used to
     * indicate an invalid epochSeconds. Use LocalDate::forEpochSeconds() or
     * LocalDateTime::forEpochSeconds() to obtain the minimum instance of those
     * classes.
     */
    static const acetime_t kMinEpochSeconds = INT32_MIN + 1;

    /**
     * Maximum valid epochSeconds. Use LocalDate::forEpochSeconds() or
     * LocalDateTime::forEpochSeconds() to obtain the maximum instance of those
     * classes.
     */
    static const acetime_t kMaxEpochSeconds = INT32_MAX;

    /** Monday ISO 8601 number. */
    static const uint8_t kMonday = 1;

    /** Tuesday ISO 8601 number. */
    static const uint8_t kTuesday = 2;

    /** Wednesday ISO 8601 number. */
    static const uint8_t kWednesday = 3;

    /** Thursday ISO 8601 number. */
    static const uint8_t kThursday = 4;

    /** Friday ISO 8601 number. */
    static const uint8_t kFriday = 5;

    /** Saturday ISO 8601 number. */
    static const uint8_t kSaturday = 6;

    /** Sunday ISO 8601 number. */
    static const uint8_t kSunday = 7;

  // Utility functions
  public:
    /** True if year is a leap year. */
    static bool isLeapYear(int16_t year) {
      return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    }

    /** Return the number of days in the given (year, month). */
    static uint8_t daysInMonth(int16_t year, uint8_t month) {
      uint8_t days = sDaysInMonth[month - 1];
      return (month == 2 && isLeapYear(year)) ? days + 1 : days;
    }

    /** Return true if year is within the range of `[0,10000]` */
    static bool isYearValid(int16_t year) {
      return year >= kMinYear && year <= kMaxYear;
    }

  // Set and get local epoch year.
  public:
    /** Base year of local epoch. The actual epoch is yyyy-01-01. */
    static int16_t sLocalEpochYear;

    /**
     * Number of days from T_CONVERTER::kEpochConverterBaseYear to
     * sLocalEpochYear. Default is 0, since the default sLocalEpochYear is the
     * same as T_CONVERTER::kEpochConverterBaseYear.
     */
    static int32_t sDaysToLocalEpochFromBaseEpoch;

    /** Get the local epoch year. */
    static int16_t localEpochYear() {
      return sLocalEpochYear;
    }

    /** Set the local epoch year. */
    static void localEpochYear(int16_t year) {
      sLocalEpochYear = year;
      sDaysToLocalEpochFromBaseEpoch = T_CONVERTER::toEpochDays(year, 1, 1);
    }

  // Factory methods.
  public:
    /**
     * Factory method using separated year, month and day fields. Returns
     * LocalDate::forError() if the parameters are out of range.
     *
     * @param year [0,10000]
     * @param month month with January=1, December=12
     * @param day day of month [1-31]
     */
    static LocalDateTemplate forComponents(
        int16_t year, uint8_t month, uint8_t day) {
      year = isYearValid(year) ? year : kInvalidYear;
      return LocalDateTemplate(year, month, day);
    }

    /**
     * Factory method using the number of days since the current epoch (usually
     * 2000-01-01). If epochDays is kInvalidEpochDays, isError() will return
     * true.
     *
     * @param epochDays number of days since the current local epoch
     */
    static LocalDateTemplate forEpochDays(int32_t epochDays) {
      int16_t year;
      uint8_t month;
      uint8_t day;
      if (epochDays == kInvalidEpochDays) {
        year = kInvalidYear;
        month = 0;
        day = 0;
      } else {
        // shift relative to T_CONVERTER::kEpochConverterBaseYear
        epochDays += sDaysToLocalEpochFromBaseEpoch;
        T_CONVERTER::fromEpochDays(epochDays, year, month, day);
      }
      return forComponents(year, month, day);
    }

    /** Factory method using the number of days since Unix epoch 1970-01-01. */
    static LocalDateTemplate forUnixDays(int32_t unixDays) {
      if (unixDays == kInvalidEpochDays) {
        return forError();
      }

      int32_t days = unixDays
          // relative to 2000
          - kDaysToBaseEpochFromUnixEpoch
          // relative to local epoch
          - sDaysToLocalEpochFromBaseEpoch;
      return forEpochDays(days);
    }

    /**
     * Factory method using the number of seconds since the current epoch year
     * given by `localEpochYear()`. The default is 2000-01-01, but can be
     * changed using `localEpochYear(epochYear)`.
     *
     * The number of seconds from midnight of the given day is thrown away. For
     * negative values of epochSeconds, the method to rounds down to the nearest
     * day.
     *
     * If epochSeconds is kInvalidEpochSeconds, isError() will return true.
     *
     * @param epochSeconds number of seconds since the current local epoch
     */
    static LocalDateTemplate forEpochSeconds(acetime_t epochSeconds) {
      if (epochSeconds == kInvalidEpochSeconds) {
        return forError();
      }

      // integer floor-division towards -infinity
      int32_t days = (epochSeconds < 0)
          ? (epochSeconds + 1) / 86400 - 1
          : epochSeconds / 86400;
      return forEpochDays(days);
    }

    /**
     * Factory method that takes the 64-bit number of seconds since Unix Epoch
     * of 1970-01-01. Similar to forEpochSeconds(), the seconds corresponding to
     * the partial day are truncated down towards the smallest whole day. Valid
     * over the entire range of year `[0,10000]` due to the use of `int64_t`
     * operations.
     */
    static LocalDateTemplate forUnixSeconds64(int64_t unixSeconds) {
      if (unixSeconds == kInvalidEpochSeconds64) {
        return forError();
      } else {
        int64_t epochSeconds64 = unixSeconds
            // relative to base epoch (2000)
            - kSecondsToBaseEpochFromUnixEpoch
            // relative to local epoch
            - sDaysToLocalEpochFromBaseEpoch * (int64_t) 86400;
        int32_t days = (epochSeconds64 < 0)
            ? (epochSeconds64 + 1) / 86400 - 1
            : epochSeconds64 / 86400;
        return forEpochDays(days);
      }
    }

    /**
     * Factory method. Create a LocalDate from the ISO 8601 date string. If the
     * string cannot be parsed, then isError() on the constructed object returns
     * true, but the data validation is very weak. Year should be between 0001
     * and 9999. Created for mostly for debugging purposes not for production
     * use.
     *
     * @param dateString the date in ISO 8601 format (yyyy-mm-dd)
     */
    static LocalDateTemplate forDateString(const char* dateString) {
      if (strlen(dateString) < kDateStringLength) {
        return forError();
      }
      return forDateStringChainable(dateString);
    }

    /**
     * Variant of forDateString() that updates the pointer to the next
     * unprocessed character. This allows chaining to another
     * forXxxStringChainable() method.
     *
     * This method assumes that the dateString is sufficiently long.
     */
    static LocalDateTemplate forDateStringChainable(const char*& dateString) {
      const char* s = dateString;

      // year (assumes 4 digit year)
      int16_t year = (*s++ - '0');
      year = 10 * year + (*s++ - '0');
      year = 10 * year + (*s++ - '0');
      year = 10 * year + (*s++ - '0');

      // '-'
      s++;

      // month
      uint8_t month = (*s++ - '0');
      month = 10 * month + (*s++ - '0');

      // '-'
      s++;

      // day
      uint8_t day = (*s++ - '0');
      day = 10 * day + (*s++ - '0');

      dateString = s;
      return forComponents(year, month, day);
    }

    /**
     * Factory method that returns a LocalDate which represents an error
     * condition. The isError() method will return true.
     */
    static LocalDateTemplate forError() {
      return LocalDateTemplate(kInvalidYear, 0, 0);
    }

  // Instance methods.
  public:
    /** Default constructor does nothing. */
    explicit LocalDateTemplate() = default;

    /** Return the year. */
    int16_t year() const { return mYear; }

    /** Set the year. */
    void year(int16_t year) { mYear = year; }

    /** Return the month with January=1, December=12. */
    uint8_t month() const { return mMonth; }

    /** Set the month. */
    void month(uint8_t month) { mMonth = month; }

    /** Return the day of the month. */
    uint8_t day() const { return mDay; }

    /** Set the day of the month. */
    void day(uint8_t day) { mDay = day; }

    /**
     * Calculate the day of week given the (year, month, day). Idea borrowed
     * from https://github.com/evq/utz. No validation of year, month or day is
     * performed. If this is found to be too slow, then consider caching the
     * results.
     */
    uint8_t dayOfWeek() const {
      // The "year" starts in March to shift leap year calculation to end.
      int16_t y = year() - (mMonth < 3);
      int16_t d = y + y/4 - y/100 + y/400 + sDayOfWeek[mMonth-1] + mDay;

      // 2000-01-01 was a Saturday=6, so set the offsets accordingly
      return (d < -1) ? (d + 1) % 7 + 8 : (d + 1) % 7 + 1;
    }

    /** Return true if any component indicates an error condition. */
    bool isError() const {
      return mYear == kInvalidYear
          || mDay < 1 || mDay > 31
          || mMonth < 1 || mMonth > 12;
    }

    /**
     * Return number of days since the local epoch year `sLocalEpochYear`.
     * By default, the local epoch year is 2000 so the epoch is 2000-01-01
     * 00:00:00 UTC).
     *
     * Returns kInvalidEpochDays if isError() is true, which allows round trip
     * conversions of forEpochDays() and toEpochDays() even when isError() is
     * true.
     */
    int32_t toEpochDays() const {
      if (isError()) return kInvalidEpochDays;
      int32_t days = T_CONVERTER::toEpochDays(mYear, mMonth, mDay)
          - sDaysToLocalEpochFromBaseEpoch; // relative to local epoch
      return days;
    }

    /** Return the number of days since Unix epoch (1970-01-01 00:00:00). */
    int32_t toUnixDays() const {
      if (isError()) return kInvalidEpochDays;
      return toEpochDays()
          + sDaysToLocalEpochFromBaseEpoch // relative to base epoch year
          + kDaysToBaseEpochFromUnixEpoch; // relative to 1970
    }

    /**
     * Return the number of seconds since the localEpochYear().
     *
     * Returns kInvalidEpochSeconds if isError() is true or if epochSeconds is
     * out of range.
     */
    acetime_t toEpochSeconds() const {
      if (isError()) return kInvalidEpochSeconds;
      return (int32_t) 86400 * toEpochDays();
    }

    /**
     * Return the number of seconds since Unix epoch (1970-01-01 00:00:00).
     */
    int64_t toUnixSeconds64() const {
      if (isError()) return kInvalidEpochSeconds64;
      return (int64_t) 86400 * toUnixDays();
    }

    /**
     * Compare 'this' LocalDate to 'that' LocalDate, returning (<0, 0, >0)
     * according to whether 'this' occurs (before, same as, after) 'that'. If
     * either this->isError() or that.isError() is true, the behavior is
     * undefined.
     */
    int8_t compareTo(const LocalDateTemplate& that) const {
      if (mYear < that.mYear) return -1;
      if (mYear > that.mYear) return 1;
      if (mMonth < that.mMonth) return -1;
      if (mMonth > that.mMonth) return 1;
      if (mDay < that.mDay) return -1;
      if (mDay > that.mDay) return 1;
      return 0;
    }

    /**
     * Print LocalDate to 'printer' in ISO 8601 format, along with the
     * day of week.
     * This class does not implement the Printable interface to avoid
     * increasing the size of the object from the additional virtual function.
     */
    void printTo(Print& printer) const {
      if (isError()) {
        printer.print(F("<Invalid LocalDate>"));
        return;
      }

      // Date
      using ace_common::printPad2To;
      printer.print(year());
      printer.print('-');
      printPad2To(printer, mMonth, '0');
      printer.print('-');
      printPad2To(printer, mDay, '0');
      printer.print(' ');

      // Week day
      DateStrings ds;
      printer.print(ds.dayOfWeekLongString(dayOfWeek()));
    }

    // Use default copy constructor and assignment operator.
    LocalDateTemplate(const LocalDateTemplate&) = default;
    LocalDateTemplate& operator=(const LocalDateTemplate&) = default;

  private:
    template <typename T>
    friend bool operator==(
        const LocalDateTemplate<T>& a, const LocalDateTemplate<T>& b);

    /** Constructor that sets the components. */
    explicit LocalDateTemplate(int16_t year, uint8_t month, uint8_t day):
        mYear(year),
        mMonth(month),
        mDay(day) {}

  private:
    /** Minimum length of the date string. yyyy-mm-dd. */
    static const uint8_t kDateStringLength = 10;

    /**
     * Day of week table for each month, with 0=Jan to 11=Dec. The table
     * offsets actually start with March, causing the leap year to happen at
     * the end of the "year", which makes the leap year calculation easier.
     */
    static const uint8_t sDayOfWeek[12];

    /** Number of days in each month in a non-leap year. 0=Jan, 11=Dec. */
    static const uint8_t sDaysInMonth[12];

    int16_t mYear; // [0,10000], INT16_MIN indicates error
    uint8_t mMonth; // [1, 12], 0 indicates error
    uint8_t mDay; // [1, 31], 0 indicates error
};

/** Return true if two LocalDate objects are equal in all components. */
template <typename T>
bool operator==(const LocalDateTemplate<T>& a, const LocalDateTemplate<T>& b) {
  return a.mDay == b.mDay
      && a.mMonth == b.mMonth
      && a.mYear == b.mYear;
}

/** Return true if two LocalDate objects are not equal. */
template <typename T>
bool operator!=(const LocalDateTemplate<T>& a, const LocalDateTemplate<T>& b) {
  return ! (a == b);
}

// Using 0=Jan offset.
template <typename T>
const uint8_t LocalDateTemplate<T>::sDayOfWeek[12] = {
  5 /*Jan=31*/,
  1 /*Feb=28*/,
  0 /*Mar=31, start of "year"*/,
  3 /*Apr=30*/,
  5 /*May=31*/,
  1 /*Jun=30*/,
  3 /*Jul=31*/,
  6 /*Aug=31*/,
  2 /*Sep=30*/,
  4 /*Oct=31*/,
  0 /*Nov=30*/,
  2 /*Dec=31*/,
};

// Using 0=Jan offset.
template <typename T>
const uint8_t LocalDateTemplate<T>::sDaysInMonth[12] = {
  31 /*Jan=31*/,
  28 /*Feb=28*/,
  31 /*Mar=31*/,
  30 /*Apr=30*/,
  31 /*May=31*/,
  30 /*Jun=30*/,
  31 /*Jul=31*/,
  31 /*Aug=31*/,
  30 /*Sep=30*/,
  31 /*Oct=31*/,
  30 /*Nov=30*/,
  31 /*Dec=31*/,
};

template <typename T>
int16_t LocalDateTemplate<T>::sLocalEpochYear = 2000;

template <typename T>
int32_t LocalDateTemplate<T>::sDaysToLocalEpochFromBaseEpoch = 0;

// Use EpochConverterHinnant for LocalDate
using LocalDate = LocalDateTemplate<internal::EpochConverterHinnant>;

}

#endif
