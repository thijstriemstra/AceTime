#line 2 "ExtendedBrokerTest.ino"

#include <Arduino.h>
#include <AUnit.h>
#include <AceTime.h>
#include <ace_time/testing/tzonedbx/zone_policies.h>
#include <ace_time/testing/tzonedbx/zone_infos.h>
#include <ace_time/testing/tzonedbx/zone_registry.h>

using namespace ace_time;
using ace_time::internal::ZoneContext;
using ace_time::extended::ZoneInfoBroker;
using ace_time::extended::ZoneEraBroker;
using ace_time::extended::ZoneRuleBroker;
using ace_time::extended::ZonePolicyBroker;
using ace_time::extended::LinkEntryBroker;
using ace_time::extended::LinkRegistryBroker;
using ace_time::tzonedbx::kZoneContext;
using ace_time::tzonedbx::kZonePolicyUS;
using ace_time::tzonedbx::kZoneAmerica_Los_Angeles;
using ace_time::tzonedbx::kZonePolicyNamibia;
using ace_time::tzonedbx::kLinkRegistry;
using ace_time::tzonedbx::kZoneIdUS_Pacific;
using ace_time::tzonedbx::kZoneIdAmerica_Los_Angeles; 

//---------------------------------------------------------------------------

test(timeCodeToMinutes) {
  uint8_t code = 1;
  uint8_t modifier = 0x01;
  assertEqual((uint16_t)16,
      ace_time::internal::timeCodeToMinutes(code, modifier));
}

//---------------------------------------------------------------------------

test(ExtendedBrokerTest, ZoneRuleBroker) {
  ZoneRuleBroker rule(&kZonePolicyUS.rules[0]);
  assertFalse(rule.isNull());
  assertEqual(1967, rule.fromYear());
  assertEqual(2006, rule.toYear());
  assertEqual(10, rule.inMonth());
  assertEqual(7, rule.onDayOfWeek());
  assertEqual(0, rule.onDayOfMonth());
  assertEqual((uint16_t)120, rule.atTimeMinutes());
  assertEqual(ZoneContext::kSuffixW, rule.atTimeSuffix());
  assertEqual(0, rule.deltaMinutes());
  assertEqual((uint8_t)'S', rule.letter());
}

test(ExtendedBrokerTest, ZonePolicyBroker) {
  ZonePolicyBroker policy(&kZonePolicyUS);
  assertFalse(policy.isNull());
  assertEqual(6, policy.numRules());
  assertEqual(0, policy.numLetters());
}

test(ExtendedBrokerTest, ZonePolicyBroker_with_letters) {
  ZonePolicyBroker policy(&kZonePolicyNamibia);
  assertFalse(policy.isNull());
  assertEqual(4, policy.numRules());
  assertEqual(2, policy.numLetters());
  assertEqual(F("CAT"), policy.letter(0));
  assertEqual(F("WAT"), policy.letter(1));
}

test(ExtendedBrokerTest, ZoneEraBroker) {
  ZoneEraBroker era(
      &((const extended::ZoneEra*)kZoneAmerica_Los_Angeles.eras)[0]);
  assertFalse(era.isNull());
  assertEqual(-32 * 15, era.offsetMinutes());
  assertEqual(0, era.deltaMinutes());
  assertEqual("P%T", era.format());
  assertEqual((int16_t)10000, era.untilYear());
  assertEqual((uint8_t)1, era.untilMonth());
  assertEqual((uint8_t)1, era.untilDay());
  assertEqual((uint16_t)0, era.untilTimeMinutes());
  assertEqual(ZoneContext::kSuffixW, era.untilTimeSuffix());

  ZoneEraBroker era2(
    &((const extended::ZoneEra*)kZoneAmerica_Los_Angeles.eras)[0]);
  assertTrue(era.equals(era2));
}

test(ExtendedBrokerTest, ZoneInfoBroker) {
  ZoneInfoBroker info(&kZoneAmerica_Los_Angeles);
  assertEqual(&kZoneContext, info.zoneContext());
  assertEqual("America/Los_Angeles", info.name());
  assertEqual((uint32_t) 0xb7f7e8f2, info.zoneId());
  assertEqual(1980, info.zoneContext()->startYear);
  assertEqual(10000, info.zoneContext()->untilYear);
  assertEqual(1, info.numEras());
}

//---------------------------------------------------------------------------

test(ExtendedBrokerTest, LinkRegistry_LinkEntryBroker) {
  LinkRegistryBroker linkRegistryBroker(kLinkRegistry);
  LinkEntryBroker linkEntryBroker(linkRegistryBroker.linkEntry(0));
  assertEqual(kZoneIdUS_Pacific, linkEntryBroker.linkId());
  assertEqual(kZoneIdAmerica_Los_Angeles, linkEntryBroker.zoneId());
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
