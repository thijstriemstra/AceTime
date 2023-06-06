#line 2 "CompleteBrokerTest.ino"

#include <Arduino.h>
#include <AUnit.h>
#include <AceTime.h>
#include <tzonedbc/zone_policies.h>
#include <tzonedbc/zone_infos.h>
#include <tzonedbc/zone_registry.h>

using namespace ace_time;
using ace_time::complete::ZoneContext;
using ace_time::complete::ZoneInfoBroker;
using ace_time::complete::ZoneEraBroker;
using ace_time::complete::ZoneRuleBroker;
using ace_time::complete::ZonePolicyBroker;
using ace_time::complete::ZoneEra;
using ace_time::tzonedbc::kZoneContext;
using ace_time::tzonedbc::kZonePolicyUS;
using ace_time::tzonedbc::kZoneAmerica_Los_Angeles;
using ace_time::tzonedbc::kZonePolicyNamibia;
using ace_time::tzonedbc::kZoneIdUS_Pacific;
using ace_time::tzonedbc::kZoneIdAmerica_Los_Angeles;

//---------------------------------------------------------------------------

test(timeCodeToSeconds) {
  uint16_t code = 1;
  uint8_t modifier = 0x01;
  assertEqual((uint32_t)16,
      ace_time::zoneinfohires::timeCodeToSeconds(code, modifier));
}

//---------------------------------------------------------------------------

test(CompleteBrokerTest, ZoneRuleBroker) {
  ZoneRuleBroker rule(&kZoneContext, &kZonePolicyUS.rules[1]);
  assertFalse(rule.isNull());
  assertEqual(1967, rule.fromYear());
  assertEqual(2006, rule.toYear());
  assertEqual(10, rule.inMonth());
  assertEqual(7, rule.onDayOfWeek());
  assertEqual(0, rule.onDayOfMonth());
  assertEqual((uint32_t)2*60*60, rule.atTimeSeconds());
  assertEqual(ZoneContext::kSuffixW, rule.atTimeSuffix());
  assertEqual(0, rule.deltaSeconds());
  assertEqual((uint8_t)'S', rule.letter());
}

test(CompleteBrokerTest, ZonePolicyBroker) {
  ZonePolicyBroker policy(&kZoneContext, &kZonePolicyUS);
  assertFalse(policy.isNull());
  assertEqual(7, policy.numRules());
}

test(CompleteBrokerTest, ZonePolicyBroker_with_letters) {
  ZonePolicyBroker policy(&kZoneContext, &kZonePolicyNamibia);
  assertFalse(policy.isNull());
  assertEqual(4, policy.numRules());
}

test(CompleteBrokerTest, ZoneEraBroker) {
  ZoneEraBroker era(&kZoneContext, &kZoneAmerica_Los_Angeles.eras[0]);
  assertFalse(era.isNull());
  assertEqual(-8*60*60, era.offsetSeconds());
  assertEqual(0, era.deltaSeconds());
  assertEqual("P%T", era.format());
  assertEqual(ZoneContext::kMaxUntilYear, era.untilYear());
  assertEqual((uint8_t)1, era.untilMonth());
  assertEqual((uint8_t)1, era.untilDay());
  assertEqual((uint32_t)0, era.untilTimeSeconds());
  assertEqual(ZoneContext::kSuffixW, era.untilTimeSuffix());

  ZoneEraBroker era2(&kZoneContext, &kZoneAmerica_Los_Angeles.eras[0]);
  assertTrue(era.equals(era2));
}

test(CompleteBrokerTest, ZoneInfoBroker) {
  ZoneInfoBroker info(&kZoneAmerica_Los_Angeles);
  assertEqual(&kZoneContext, info.zoneContext().raw());
  assertEqual("America/Los_Angeles", info.name());
  assertEqual((uint32_t) 0xb7f7e8f2, info.zoneId());
  assertEqual(1980, info.zoneContext().startYear());
  assertEqual(10000, info.zoneContext().untilYear());
  assertEqual(1, info.numEras());
}

//---------------------------------------------------------------------------

void setup() {
#if ! defined(EPOXY_DUINO)
  delay(1000); // wait to prevent garbage on SERIAL_PORT_MONITOR
#endif
  SERIAL_PORT_MONITOR.begin(115200);
  while (!SERIAL_PORT_MONITOR); // Leonardo/Micro
#if defined(EPOXY_DUINO)
  SERIAL_PORT_MONITOR.setLineModeUnix();
#endif
}

void loop() {
  aunit::TestRunner::run();
}
