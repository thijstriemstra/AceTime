#line 2 "ExtendedZoneSpecifierTest.ino"

#include <AUnit.h>
#include <AceTime.h>

using namespace aunit;
using namespace ace_time;
using namespace ace_time::extended;

// --------------------------------------------------------------------------
// ExtendedZoneSpecifier
// --------------------------------------------------------------------------

test(ExtendedZoneSpecifierTest, compareEraToYearMonth) {
  common::ZoneEra era = {0, nullptr, 0, "", 0, 1, 2, 12, 'w'};
  assertEqual(1, ExtendedZoneSpecifier::compareEraToYearMonth(&era, 0, 1));
  assertEqual(1, ExtendedZoneSpecifier::compareEraToYearMonth(&era, 0, 1));
  assertEqual(-1, ExtendedZoneSpecifier::compareEraToYearMonth(&era, 0, 2));
  assertEqual(-1, ExtendedZoneSpecifier::compareEraToYearMonth(&era, 0, 3));

  common::ZoneEra era2 = {0, nullptr, 0, "", 0, 1, 0, 0, 'w'};
  assertEqual(0, ExtendedZoneSpecifier::compareEraToYearMonth(&era2, 0, 1));
}

test(ExtendedZoneSpecifierTest, createMatch) {
  // UNTIL = 2000-01-02 3:00
  common::ZoneEra prev = {0, nullptr, 0, "", 0, 1, 2, 3, 'w'};
  // UNTIL = 2002-03-04 5:00
  common::ZoneEra era = {0, nullptr, 0, "", 2, 3, 4, 5, 'w'};

  extended::YearMonthTuple startYm = {0, 12};
  extended::YearMonthTuple untilYm = {1, 2};
  extended::ZoneMatch match = ExtendedZoneSpecifier::createMatch(
      &prev, &era, startYm, untilYm);
  assertTrue((match.startDateTime == extended::DateTuple{0, 12, 1, 0, 'w'}));
  assertTrue((match.untilDateTime == extended::DateTuple{1, 2, 1, 0, 'w'}));
  assertTrue(&era == match.era);

  startYm = {-1, 12};
  untilYm = {3, 2};
  match = ExtendedZoneSpecifier::createMatch(&prev, &era, startYm, untilYm);
  assertTrue((match.startDateTime == extended::DateTuple{0, 1, 2, 3, 'w'}));
  assertTrue((match.untilDateTime == extended::DateTuple{2, 3, 4, 5, 'w'}));
  assertTrue(&era == match.era);
}

test(ExtendedZoneSpecifierTest, findMatches) {
  // TODO: Implement
}

test(ExtendedZoneSpecifierTest, getTransitionTime) {
  // TODO: Implement
}

test(ExtendedZoneSpecifierTest, createTransitionForYear) {
  // TODO: Implement
}

test(ExtendedZoneSpecifierTest, normalizeDateTuple) {
  DateTuple dtp;

  dtp = {0, 1, 1, 0, 'w'};
  ExtendedZoneSpecifier::normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{0, 1, 1, 0, 'w'}));

  dtp = {0, 1, 1, 95, 'w'};
  ExtendedZoneSpecifier::normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{0, 1, 1, 95, 'w'}));

  dtp = {0, 1, 1, 96, 'w'};
  ExtendedZoneSpecifier::normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{0, 1, 2, 0, 'w'}));

  dtp = {0, 1, 1, 97, 'w'};
  ExtendedZoneSpecifier::normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{0, 1, 2, 1, 'w'}));

  dtp = {0, 1, 1, -96, 'w'};
  ExtendedZoneSpecifier::normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{-01, 12, 31, 0, 'w'}));

  dtp = {0, 1, 1, -97, 'w'};
  ExtendedZoneSpecifier::normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{-01, 12, 31, -1, 'w'}));
}

test(ExtendedZoneSpecifierTest, expandDateTuple) {
  DateTuple tt;
  DateTuple tts;
  DateTuple ttu;
  int8_t offsetCode = 8;
  int8_t deltaCode = 4;

  tt = {0, 1, 30, 12, 'w'};
  ExtendedZoneSpecifier::expandDateTuple(&tt, &tts, &ttu,
      offsetCode, deltaCode);
  assertTrue((tt == DateTuple{0, 1, 30, 12, 'w'}));
  assertTrue((tts == DateTuple{0, 1, 30, 8, 's'}));
  assertTrue((ttu == DateTuple{0, 1, 30, 0, 'u'}));

  tt = {0, 1, 30, 8, 's'};
  ExtendedZoneSpecifier::expandDateTuple(&tt, &tts, &ttu,
      offsetCode, deltaCode);
  assertTrue((tt == DateTuple{0, 1, 30, 12, 'w'}));
  assertTrue((tts == DateTuple{0, 1, 30, 8, 's'}));
  assertTrue((ttu == DateTuple{0, 1, 30, 0, 'u'}));

  tt = {0, 1, 30, 0, 'u'};
  ExtendedZoneSpecifier::expandDateTuple(&tt, &tts, &ttu,
      offsetCode, deltaCode);
  assertTrue((tt == DateTuple{0, 1, 30, 12, 'w'}));
  assertTrue((tts == DateTuple{0, 1, 30, 8, 's'}));
  assertTrue((ttu == DateTuple{0, 1, 30, 0, 'u'}));
}

test(ExtendedZoneSpecifierTest, calcInteriorYears) {
  const uint8_t kMaxInteriorYears = 4;
  int8_t interiorYears[kMaxInteriorYears];

  uint8_t num = ExtendedZoneSpecifier::calcInteriorYears(
      interiorYears, kMaxInteriorYears, -2, -1, 0, 2);
  assertEqual(0, num);

  num = ExtendedZoneSpecifier::calcInteriorYears(
      interiorYears, kMaxInteriorYears, 3, 5, 0, 2);
  assertEqual(0, num);

  num = ExtendedZoneSpecifier::calcInteriorYears(
      interiorYears, kMaxInteriorYears, -2, 0, 0, 2);
  assertEqual(1, num);
  assertEqual(0, interiorYears[0]);

  num = ExtendedZoneSpecifier::calcInteriorYears(
      interiorYears, kMaxInteriorYears, 2, 4, 0, 2);
  assertEqual(1, num);
  assertEqual(2, interiorYears[0]);

  num = ExtendedZoneSpecifier::calcInteriorYears(
      interiorYears, kMaxInteriorYears, 1, 2, 0, 2);
  assertEqual(2, num);
  assertEqual(1, interiorYears[0]);
  assertEqual(2, interiorYears[1]);

  num = ExtendedZoneSpecifier::calcInteriorYears(
      interiorYears, kMaxInteriorYears, -1, 3, 0, 2);
  assertEqual(3, num);
  assertEqual(0, interiorYears[0]);
  assertEqual(1, interiorYears[1]);
  assertEqual(2, interiorYears[2]);
}

test(ExtendedZoneSpecifierTest, getMostRecentPriorYear) {
  int8_t yearTiny;

  yearTiny = ExtendedZoneSpecifier::getMostRecentPriorYear(-2, -1, 0, 2);
  assertEqual(-1, yearTiny);

  yearTiny = ExtendedZoneSpecifier::getMostRecentPriorYear(3, 5, 0, 2);
  assertEqual(LocalDate::kInvalidYearTiny, yearTiny);

  yearTiny = ExtendedZoneSpecifier::getMostRecentPriorYear(-2, 0, 0, 2);
  assertEqual(-1, yearTiny);

  yearTiny = ExtendedZoneSpecifier::getMostRecentPriorYear(2, 4, 0, 2);
  assertEqual(LocalDate::kInvalidYearTiny, yearTiny);

  yearTiny = ExtendedZoneSpecifier::getMostRecentPriorYear(1, 2, 0, 2);
  assertEqual(LocalDate::kInvalidYearTiny, yearTiny);

  yearTiny = ExtendedZoneSpecifier::getMostRecentPriorYear(-1, 3, 0, 2);
  assertEqual(-1, yearTiny);
}

test(ExtendedZoneSpecifierTest, compareTransitionToMatchFuzzy) {
  const ZoneMatch match = {
    {0, 1, 1, 0, 'w'} /* startDateTime */,
    {1, 1, 1, 0, 'w'} /* untilDateTime */,
    nullptr
  };

  extended::Transition transition = {
    &match /*match*/, nullptr /*rule*/, {-1, 11, 1, 0, 'w'} /*transitionTime*/,
    {}, {}, {}, {0}, 0, false
  };
  assertEqual(-1, ExtendedZoneSpecifier::compareTransitionToMatchFuzzy(
      &transition, &match));

  transition = {
    &match /*match*/, nullptr /*rule*/, {-1, 12, 1, 0, 'w'} /*transitionTime*/,
    {}, {}, {}, {0}, 0, false
  };
  assertEqual(1, ExtendedZoneSpecifier::compareTransitionToMatchFuzzy(
      &transition, &match));

  transition = {
    &match /*match*/, nullptr /*rule*/, {0, 1, 1, 0, 'w'} /*transitionTime*/,
    {}, {}, {}, {0}, 0, false
  };
  assertEqual(1, ExtendedZoneSpecifier::compareTransitionToMatchFuzzy(
      &transition, &match));

  transition = {
    &match /*match*/, nullptr /*rule*/, {1, 1, 1, 0, 'w'} /*transitionTime*/,
    {}, {}, {}, {0}, 0, false
  };
  assertEqual(1, ExtendedZoneSpecifier::compareTransitionToMatchFuzzy(
      &transition, &match));

  transition = {
    &match /*match*/, nullptr /*rule*/, {1, 2, 1, 0, 'w'} /*transitionTime*/,
    {}, {}, {}, {0}, 0, false
  };
  assertEqual(1, ExtendedZoneSpecifier::compareTransitionToMatchFuzzy(
      &transition, &match));

  transition = {
    &match /*match*/, nullptr /*rule*/, {1, 3, 1, 0, 'w'} /*transitionTime*/,
    {}, {}, {}, {0}, 0, false
  };
  assertEqual(2, ExtendedZoneSpecifier::compareTransitionToMatchFuzzy(
      &transition, &match));
}


test(ExtendedZoneSpecifierTest, compareTransitionToMatch) {
  const ZoneMatch match = {
    {0, 1, 1, 0, 'w'} /*startDateTime*/,
    {1, 1, 1, 0, 'w'} /*untilDateTime*/,
    nullptr /*era*/
  };

  extended::Transition transition = {
    &match /*match*/, nullptr /*rule*/, {-1, 12, 31, 0, 'w'} /*transitionTime*/,
    {}, {}, {}, {0}, 0, false
  };
  assertEqual(-1, ExtendedZoneSpecifier::compareTransitionToMatch(
      &transition, &match));

  transition = {
    &match /*match*/, nullptr /*rule*/, {0, 1, 1, 0, 'w'} /*transitionTime*/,
    {}, {}, {}, {0}, 0, false
  };
  assertEqual(0, ExtendedZoneSpecifier::compareTransitionToMatch(
      &transition, &match));

  transition = {
    &match /*match*/, nullptr /*rule*/, {0, 1, 2, 0, 'w'} /*transitionTime*/,
    {}, {}, {}, {0}, 0, false
  };
  assertEqual(1, ExtendedZoneSpecifier::compareTransitionToMatch(
      &transition, &match));

  transition = {
    &match /*match*/, nullptr /*rule*/, {1, 1, 2, 0, 'w'} /*transitionTime*/,
    {}, {}, {}, {0}, 0, false
  };
  assertEqual(2, ExtendedZoneSpecifier::compareTransitionToMatch(
      &transition, &match));
}

test(ExtendedZoneSpecifierTest, processActiveTransition) {
  // TODO: Implement
}

test(ExtendedZoneSpecifierTest, generateStartUntilTimes) {
  // TODO: Implement
}

test(ExtendedZoneSpecifierTest, calcAbbreviations) {
  // TODO: Implement
}

test(ExtendedZoneSpecifierTest, fixTransitionTimes) {
  // TODO: Implement
}

// --------------------------------------------------------------------------
// TransitionStorage
// --------------------------------------------------------------------------

test(TransitionStorageTest, getFreeAgent) {
  TransitionStorage<4> storage;
  storage.init();

  Transition* freeAgent = storage.getFreeAgent();
  assertTrue(freeAgent == &storage.mPool[0]);
}

test(TransitionStorageTest, addFreeAgentToActivePool) {
  TransitionStorage<4> storage;
  storage.init();

  Transition* freeAgent = storage.getFreeAgent();
  assertTrue(freeAgent == &storage.mPool[0]);

  storage.addFreeAgentToActivePool();
  assertEqual(1, storage.mIndexPrior);
  assertEqual(1, storage.mIndexCandidates);
  assertEqual(1, storage.mIndexFree);
}

test(TransitionStorageTest, reservePrior) {
  TransitionStorage<4> storage;
  storage.init();
  Transition* prior = storage.reservePrior();
  assertTrue(prior == &storage.mPool[0]);
  assertEqual(0, storage.mIndexPrior);
  assertEqual(1, storage.mIndexCandidates);
  assertEqual(1, storage.mIndexFree);

  storage.addPriorToCandidatePool();
  assertEqual(0, storage.mIndexPrior);
  assertEqual(0, storage.mIndexCandidates);
  assertEqual(1, storage.mIndexFree);
}

test(TransitionStorageTest, addFreeAgentToCandidatePool) {
  TransitionStorage<4> storage;
  storage.init();

  // create Prior to make it interesting
  /*Transition* prior =*/ storage.reservePrior();

  Transition* freeAgent = storage.getFreeAgent();
  freeAgent->transitionTime = {0, 1, 2, 3, 'w'};
  storage.addFreeAgentToCandidatePool();
  assertEqual(0, storage.mIndexPrior);
  assertEqual(1, storage.mIndexCandidates);
  assertEqual(2, storage.mIndexFree);

  freeAgent = storage.getFreeAgent();
  freeAgent->transitionTime = {2, 3, 4, 5, 'w'};
  storage.addFreeAgentToCandidatePool();
  assertEqual(0, storage.mIndexPrior);
  assertEqual(1, storage.mIndexCandidates);
  assertEqual(3, storage.mIndexFree);

  freeAgent = storage.getFreeAgent();
  freeAgent->transitionTime = {1, 2, 3, 4, 'w'};
  storage.addFreeAgentToCandidatePool();
  assertEqual(0, storage.mIndexPrior);
  assertEqual(1, storage.mIndexCandidates);
  assertEqual(4, storage.mIndexFree);

  // Assert that the transitions are sorted
  assertEqual(0, storage.getTransition(1)->transitionTime.yearTiny);
  assertEqual(1, storage.getTransition(2)->transitionTime.yearTiny);
  assertEqual(2, storage.getTransition(3)->transitionTime.yearTiny);
}

// --------------------------------------------------------------------------

void setup() {
#if defined(ARDUINO)
  delay(1000); // wait for stability on some boards to prevent garbage Serial
#endif
  Serial.begin(115200); // ESP8266 default of 74880 not supported on Linux
  while(!Serial); // for the Arduino Leonardo/Micro only
}

void loop() {
  TestRunner::run();
}
