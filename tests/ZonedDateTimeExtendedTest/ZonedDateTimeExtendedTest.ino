#line 2 "ZonedDateTimeExtendedTest.ino"

#include <AUnit.h>
#include <AceCommon.h> // PrintStr
#include <AceTime.h>

using namespace aunit;
using namespace ace_time;

// --------------------------------------------------------------------------
// Create ExtendedZoneManager
// --------------------------------------------------------------------------

const extended::ZoneInfo* const kExtendedZoneRegistry[] ACE_TIME_PROGMEM = {
  &zonedbx::kZoneAmerica_Chicago,
  &zonedbx::kZoneAmerica_Denver,
  &zonedbx::kZoneAmerica_Los_Angeles,
  &zonedbx::kZoneAmerica_New_York,
};

const uint16_t kExtendedZoneRegistrySize =
    sizeof(kExtendedZoneRegistry) / sizeof(kExtendedZoneRegistry[0]);

ExtendedZoneManager<1> extendedZoneManager(
    kExtendedZoneRegistrySize, kExtendedZoneRegistry);

// --------------------------------------------------------------------------
// ZonedDateTime + ExtendedZoneManager
// --------------------------------------------------------------------------

test(ZonedDateTimeExtendedTest, printTo) {
  TimeZone tz = extendedZoneManager.createForZoneInfo(
      &zonedbx::kZoneAmerica_Los_Angeles);
  auto dt = ZonedDateTime::forComponents(2020, 1, 2, 3, 4, 5, tz);

  ace_common::PrintStr<64> dateString;
  dt.printTo(dateString);
  assertEqual(
      dateString.getCstr(),
      F("2020-01-02T03:04:05-08:00[America/Los_Angeles]")
  );
}

test(ZonedDateTimeExtendedTest, forComponents_isError) {
  TimeZone tz = extendedZoneManager.createForZoneInfo(
      &zonedbx::kZoneAmerica_Los_Angeles);

  // outside [2000, 2050) range, should generate error
  ZonedDateTime dt = ZonedDateTime::forComponents(1998, 3, 11, 1, 59, 59, tz);
  assertTrue(dt.isError());
  dt = ZonedDateTime::forComponents(2051, 3, 11, 1, 59, 59, tz);
  assertTrue(dt.isError());
}

test(ZonedDateTimeExtendedTest, forComponents_beforeDst) {
  TimeZone tz = extendedZoneManager.createForZoneInfo(
      &zonedbx::kZoneAmerica_Los_Angeles);

  // 01:59 should resolve to 01:59-08:00
  auto dt = ZonedDateTime::forComponents(2018, 3, 11, 1, 59, 0, tz);
  assertEqual(TimeOffset::forHours(-8).toMinutes(),
      dt.timeOffset().toMinutes());
  auto expected = LocalDateTime::forComponents(2018, 3, 11, 1, 59, 0);
  assertTrue(expected == dt.localDateTime());
}

test(ZonedDateTimeExtendedTest, forComponents_inDstGap) {
  TimeZone tz = extendedZoneManager.createForZoneInfo(
      &zonedbx::kZoneAmerica_Los_Angeles);

  // 02:01 doesn't exist. The expected TimeOffset in the gap is the previous
  // timeOffset, i.e. the most recent matching Transition, so this is
  // interpreted as 02:01-08:00 which gets normalized to 03:01-07:00.
  auto dt = ZonedDateTime::forComponents(2018, 3, 11, 2, 1, 0, tz);
  assertEqual(TimeOffset::forHours(-7).toMinutes(),
      dt.timeOffset().toMinutes());
  auto expected = LocalDateTime::forComponents(2018, 3, 11, 3, 1, 0);
  assertTrue(expected == dt.localDateTime());
}

test(ZonedDateTimeExtendedTest, forComponents_inDst) {
  TimeZone tz = extendedZoneManager.createForZoneInfo(
      &zonedbx::kZoneAmerica_Los_Angeles);

  // 03:01 should resolve to 03:01-07:00.
  auto dt = ZonedDateTime::forComponents(2018, 3, 11, 3, 1, 0, tz);
  assertEqual(TimeOffset::forHours(-7).toMinutes(),
      dt.timeOffset().toMinutes());
  auto expected = LocalDateTime::forComponents(2018, 3, 11, 3, 1, 0);
  assertTrue(expected == dt.localDateTime());
}

test(ZonedDateTimeExtendedTest, forComponents_beforeStd) {
  TimeZone tz = extendedZoneManager.createForZoneInfo(
      &zonedbx::kZoneAmerica_Los_Angeles);

  // 00:59 is an hour before the DST->STD transition, so should return
  // 00:59-07:00.
  auto dt = ZonedDateTime::forComponents(2018, 11, 4, 0, 59, 0, tz);
  assertEqual(TimeOffset::forHours(-7).toMinutes(),
      dt.timeOffset().toMinutes());
  auto expected = LocalDateTime::forComponents(2018, 11, 4, 0, 59, 0);
  assertTrue(expected == dt.localDateTime());
}

test(ZonedDateTimeExtendedTest, forComponents_inOverlap) {
  TimeZone tz = extendedZoneManager.createForZoneInfo(
      &zonedbx::kZoneAmerica_Los_Angeles);

  // There were two instances of 01:01. The algorithm picks the later offset,
  // i.e. the most recent matching Transition, so should resolve to 01:01-08:00.
  auto dt = ZonedDateTime::forComponents(2018, 11, 4, 1, 1, 0, tz);
  assertEqual(TimeOffset::forHours(-8).toMinutes(),
      dt.timeOffset().toMinutes());
  auto expected = LocalDateTime::forComponents(2018, 11, 4, 1, 1, 0);
  assertTrue(expected == dt.localDateTime());
}

test(ZonedDateTimeExtendedTest, forComponents_afterOverlap) {
  TimeZone tz = extendedZoneManager.createForZoneInfo(
      &zonedbx::kZoneAmerica_Los_Angeles);

  // 02:01 should resolve to 02:01-08:00
  auto dt = ZonedDateTime::forComponents(2018, 11, 4, 2, 1, 0, tz);
  assertEqual(TimeOffset::forHours(-8).toMinutes(),
      dt.timeOffset().toMinutes());
  auto expected = LocalDateTime::forComponents(2018, 11, 4, 2, 1, 0);
  assertTrue(expected == dt.localDateTime());
}

// Test the linked zones are same as the target zones.
// Commented out because this test does not work with "fat" Link which behave
// just like a normal Zone. TODO: Figure out how to detect fat links at runtime.
/*
test(ZonedDateTimeExtendedTest, linked_zones) {
  assertEqual(&zonedbx::kZoneAmerica_Los_Angeles, &zonedbx::kZoneUS_Pacific);
}
*/

// --------------------------------------------------------------------------

void setup() {
#if ! defined(EPOXY_DUINO)
  delay(1000); // wait to prevent garbage on SERIAL_PORT_MONITOR
#endif
  SERIAL_PORT_MONITOR.begin(115200);
  while (!SERIAL_PORT_MONITOR); // for Leonardo/Micro
}

void loop() {
  TestRunner::run();
}
