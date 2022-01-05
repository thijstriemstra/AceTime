#line 2 "ExtendedZoneProcessorMoreTest.ino"

// Spillovers from ExtendedZoneProcessorTest.ino after it became too big for a
// SparkFun Pro Micro.

#include <AUnit.h>
#include <AceCommon.h> // PrintStr<>
#include <AceTime.h>

using ace_common::PrintStr;
using namespace ace_time;
using ace_time::internal::ZoneContext;
using ace_time::extended::DateTuple;
using ace_time::extended::normalizeDateTuple;
using ace_time::extended::subtractDateTuple;

//---------------------------------------------------------------------------
// DateTuple.
//---------------------------------------------------------------------------

test(ExtendedZoneProcessorTest, dateTupleOperatorLessThan) {
  assertTrue((
      DateTuple{0, 1, 2, 3, ZoneContext::kSuffixW}
      < DateTuple{0, 1, 2, 4, ZoneContext::kSuffixS}));
  assertTrue((
      DateTuple{0, 1, 2, 3, ZoneContext::kSuffixW}
      < DateTuple{0, 1, 3, 3, ZoneContext::kSuffixS}));
  assertTrue((
      DateTuple{0, 1, 2, 3, ZoneContext::kSuffixW}
      < DateTuple{0, 2, 2, 3, ZoneContext::kSuffixS}));
  assertTrue((
      DateTuple{0, 1, 2, 3, ZoneContext::kSuffixW}
      < DateTuple{1, 1, 2, 3, ZoneContext::kSuffixS}));
}

test(ExtendedZoneProcessorTest, dateTupleOperatorEquals) {
  assertTrue((
      DateTuple{0, 1, 2, 3, ZoneContext::kSuffixW}
      == DateTuple{0, 1, 2, 3, ZoneContext::kSuffixW}));

  assertFalse((
      DateTuple{0, 1, 2, 3, ZoneContext::kSuffixW}
      == DateTuple{0, 1, 2, 3, ZoneContext::kSuffixS}));
  assertFalse((
      DateTuple{0, 1, 2, 3, ZoneContext::kSuffixW}
      == DateTuple{0, 1, 2, 4, ZoneContext::kSuffixW}));
  assertFalse((
      DateTuple{0, 1, 2, 3, ZoneContext::kSuffixW}
      == DateTuple{0, 1, 3, 3, ZoneContext::kSuffixW}));
  assertFalse((
      DateTuple{0, 1, 2, 3, ZoneContext::kSuffixW}
      == DateTuple{0, 2, 2, 3, ZoneContext::kSuffixW}));
  assertFalse((
      DateTuple{0, 1, 2, 3, ZoneContext::kSuffixW}
      == DateTuple{1, 1, 2, 3, ZoneContext::kSuffixW}));
}

test(ExtendedZoneProcessorTest, normalizeDateTuple) {
  DateTuple dtp;

  dtp = {0, 1, 1, 0, ZoneContext::kSuffixW};
  normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{0, 1, 1, 0, ZoneContext::kSuffixW}));

  dtp = {0, 1, 1, 15*95, ZoneContext::kSuffixW}; // 23:45
  normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{0, 1, 1, 15*95, ZoneContext::kSuffixW}));

  dtp = {0, 1, 1, 15*96, ZoneContext::kSuffixW}; // 24:00
  normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{0, 1, 2, 0, ZoneContext::kSuffixW}));

  dtp = {0, 1, 1, 15*97, ZoneContext::kSuffixW}; // 24:15
  normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{0, 1, 2, 15, ZoneContext::kSuffixW}));

  dtp = {0, 1, 1, -15*96, ZoneContext::kSuffixW}; // -24:00
  normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{-1, 12, 31, 0, ZoneContext::kSuffixW}));

  dtp = {0, 1, 1, -15*97, ZoneContext::kSuffixW}; // -24:15
  normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{-1, 12, 31, -15, ZoneContext::kSuffixW}));
}

test(ExtendedZoneProcessorTest, substractDateTuple) {
  DateTuple dta = {0, 1, 1, 0, ZoneContext::kSuffixW}; // 2000-01-01 00:00
  DateTuple dtb = {0, 1, 1, 1, ZoneContext::kSuffixW}; // 2000-01-01 00:01
  acetime_t diff = subtractDateTuple(dta, dtb);
  assertEqual(-60, diff);

  dta = {0, 1, 1, 0, ZoneContext::kSuffixW}; // 2000-01-01 00:00
  dtb = {0, 1, 2, 0, ZoneContext::kSuffixW}; // 2000-01-02 00:00
  diff = subtractDateTuple(dta, dtb);
  assertEqual((int32_t) -86400, diff);

  dta = {0, 1, 1, 0, ZoneContext::kSuffixW}; // 2000-01-01 00:00
  dtb = {0, 2, 1, 0, ZoneContext::kSuffixW}; // 2000-02-01 00:00
  diff = subtractDateTuple(dta, dtb);
  assertEqual((int32_t) -86400 * 31, diff); // January has 31 days

  dta = {0, 2, 1, 0, ZoneContext::kSuffixW}; // 2000-02-01 00:00
  dtb = {0, 3, 1, 0, ZoneContext::kSuffixW}; // 2000-03-01 00:00
  diff = subtractDateTuple(dta, dtb);
  assertEqual((int32_t) -86400 * 29, diff); // Feb 2000 is leap, 29 days
}

//---------------------------------------------------------------------------
// Test high level public methods of ExtendedZoneProcessor.
//---------------------------------------------------------------------------

test(ExtendedZoneProcessorTest, setZoneKey) {
  ExtendedZoneProcessor zoneProcessor(&zonedbx::kZoneAmerica_Los_Angeles);
  zoneProcessor.getUtcOffset(0);
  assertTrue(zoneProcessor.mIsFilled);

  zoneProcessor.setZoneKey((uintptr_t) &zonedbx::kZoneAustralia_Darwin);
  assertFalse(zoneProcessor.mIsFilled);
  zoneProcessor.getUtcOffset(0);
  assertTrue(zoneProcessor.mIsFilled);

  // Check that the cache remains valid if the zoneInfo does not change
  zoneProcessor.setZoneKey((uintptr_t) &zonedbx::kZoneAustralia_Darwin);
  assertTrue(zoneProcessor.mIsFilled);
}

// https://www.timeanddate.com/time/zone/usa/los-angeles
test(ExtendedZoneProcessorTest, Los_Angeles) {
  ExtendedZoneProcessor zoneProcessor(&zonedbx::kZoneAmerica_Los_Angeles);

  PrintStr<32> printStr;
  zoneProcessor.printNameTo(printStr);
  assertEqual(F("America/Los_Angeles"), printStr.cstr());
  printStr.flush();
  zoneProcessor.printShortNameTo(printStr);
  assertEqual(F("Los Angeles"), printStr.cstr());

  OffsetDateTime dt;
  acetime_t epochSeconds;

  dt = OffsetDateTime::forComponents(2018, 3, 11, 1, 59, 59,
      TimeOffset::forHours(-8));
  epochSeconds = dt.toEpochSeconds();
  assertEqual(-8*60, zoneProcessor.getUtcOffset(epochSeconds).toMinutes());
  assertEqual("PST", zoneProcessor.getAbbrev(epochSeconds));
  assertTrue(zoneProcessor.getDeltaOffset(epochSeconds).isZero());

  dt = OffsetDateTime::forComponents(2018, 3, 11, 2, 0, 0,
      TimeOffset::forHours(-8));
  epochSeconds = dt.toEpochSeconds();
  assertEqual(-7*60, zoneProcessor.getUtcOffset(epochSeconds).toMinutes());
  assertEqual("PDT", zoneProcessor.getAbbrev(epochSeconds));
  assertFalse(zoneProcessor.getDeltaOffset(epochSeconds).isZero());

  dt = OffsetDateTime::forComponents(2018, 11, 4, 1, 0, 0,
      TimeOffset::forHours(-7));
  epochSeconds = dt.toEpochSeconds();
  assertEqual(-7*60, zoneProcessor.getUtcOffset(epochSeconds).toMinutes());
  assertEqual("PDT", zoneProcessor.getAbbrev(epochSeconds));
  assertFalse(zoneProcessor.getDeltaOffset(epochSeconds).isZero());

  dt = OffsetDateTime::forComponents(2018, 11, 4, 1, 59, 59,
      TimeOffset::forHours(-7));
  epochSeconds = dt.toEpochSeconds();
  assertEqual(-7*60, zoneProcessor.getUtcOffset(epochSeconds).toMinutes());
  assertEqual("PDT", zoneProcessor.getAbbrev(epochSeconds));
  assertFalse(zoneProcessor.getDeltaOffset(epochSeconds).isZero());

  dt = OffsetDateTime::forComponents(2018, 11, 4, 2, 0, 0,
      TimeOffset::forHours(-7));
  epochSeconds = dt.toEpochSeconds();
  assertEqual(-8*60, zoneProcessor.getUtcOffset(epochSeconds).toMinutes());
  assertEqual("PST", zoneProcessor.getAbbrev(epochSeconds));
  assertTrue(zoneProcessor.getDeltaOffset(epochSeconds).isZero());
}

test(ExtendedZoneProcessorTest, Los_Angeles_outOfBounds) {
  ExtendedZoneProcessor zoneProcessor(&zonedbx::kZoneAmerica_Los_Angeles);
  OffsetDateTime dt;
  acetime_t epochSeconds;

  assertEqual(2000, zonedbx::kZoneAmerica_Los_Angeles.zoneContext->startYear);
  assertEqual(2050, zonedbx::kZoneAmerica_Los_Angeles.zoneContext->untilYear);

  dt = OffsetDateTime::forComponents(1998, 3, 11, 1, 59, 59,
      TimeOffset::forHours(-8));
  epochSeconds = dt.toEpochSeconds();
  assertTrue(zoneProcessor.getUtcOffset(epochSeconds).isError());
  assertTrue(zoneProcessor.getDeltaOffset(epochSeconds).isError());
  assertEqual("", zoneProcessor.getAbbrev(epochSeconds));

  dt = OffsetDateTime::forComponents(2051, 2, 1, 1, 0, 0,
      TimeOffset::forHours(-8));
  epochSeconds = dt.toEpochSeconds();
  assertTrue(zoneProcessor.getUtcOffset(epochSeconds).isError());
  assertTrue(zoneProcessor.getDeltaOffset(epochSeconds).isError());
  assertEqual("", zoneProcessor.getAbbrev(epochSeconds));
}

//---------------------------------------------------------------------------

void setup() {
#if ! defined(EPOXY_DUINO)
  delay(1000); // wait to prevent garbage on SERIAL_PORT_MONITOR
#endif
  SERIAL_PORT_MONITOR.begin(115200);
  while (!SERIAL_PORT_MONITOR); // Leonardo/Micro
}

void loop() {
  aunit::TestRunner::run();
}
