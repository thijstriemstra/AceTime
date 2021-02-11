#line 2 "ExtendedZoneProcessorTest.ino"

// Tests for the private/protected implementation functions of
// ExtendedZoneProcessor. The public ones have been moved to
// ExtendedZoneProcessorMoreTest because they became too big for the ~30kB
// limit of a Sparkfun Pro Micro.

#include <AUnit.h>
#include <AceTime.h>

using namespace aunit;
using namespace ace_time;
using ace_time::internal::ZoneContext;
using ace_time::extended::ZoneInfo;
using ace_time::extended::ZoneEra;
using ace_time::extended::ZoneRule;
using ace_time::extended::ZonePolicy;
using ace_time::extended::ZoneInfoBroker;
using ace_time::extended::ZoneEraBroker;
using ace_time::extended::ZoneRuleBroker;
using ace_time::extended::ZonePolicyBroker;
using ace_time::extended::YearMonthTuple;
using ace_time::extended::DateTuple;
using ace_time::extended::TransitionStorageTemplate;

//---------------------------------------------------------------------------
// extended::copyAndReplace()
//---------------------------------------------------------------------------

test(copyAndReplace, normal) {
  const uint8_t dstSize = 20;
  char dst[dstSize];

  extended::copyAndReplace(dst, dstSize, "NOREPLACE", '%', "S");
  assertEqual("NOREPLACE", dst);

  extended::copyAndReplace(dst, dstSize, "E%T", '%', "S");
  assertEqual("EST", dst);

  extended::copyAndReplace(dst, dstSize, "E%T", '%', "");
  assertEqual("ET", dst);
}

test(copyAndReplace, outOfBounds) {
  const uint8_t dstSize = 3;
  char dst[dstSize];

  extended::copyAndReplace(dst, dstSize, "ET%", '%', "S");
  assertEqual("ET", dst);
}

//---------------------------------------------------------------------------
// A simplified version of America/Los_Angeles, using only simple ZoneEras
// (i.e. no references to a ZonePolicy). Valid only for 2018.
//---------------------------------------------------------------------------

static const ZoneContext kZoneContext = {
  2000 /*startYear*/,
  2020 /*untilYear*/,
  "testing" /*tzVersion*/,
  0 /*numFragments*/,
  nullptr /*fragments*/,
};

// Create simplified ZoneEras which approximate America/Los_Angeles
static const ZoneEra kZoneEraAlmostLosAngeles[] ACE_TIME_PROGMEM = {
  {
    nullptr,
    "PST" /*format*/,
    -32 /*offsetCode*/,
    0 + 4 /*deltaCode*/,
    19 /*untilYearTiny*/,
    3 /*untilMonth*/,
    10 /*untilDay*/,
    2*4 /*untilTimeCode*/,
    ZoneContext::kSuffixW /*untilTimeModifier*/
  },
  {
    nullptr,
    "PDT" /*format*/,
    -32 /*offsetCode*/,
    4 + 4 /*deltaCode*/,
    19 /*untilYearTiny*/,
    11 /*untilMonth*/,
    3 /*untilDay*/,
    2*4 /*untilTimeCode*/,
    ZoneContext::kSuffixW /*untilTimeModifier*/
  },
  {
    nullptr,
    "PST" /*format*/,
    -32 /*offsetCode*/,
    0 + 4 /*deltaCode*/,
    20 /*untilYearTiny*/,
    3 /*untilMonth*/,
    8 /*untilDay*/,
    2*4 /*untilTimeCode*/,
    ZoneContext::kSuffixW /*untilTimeModifier*/
  },
};

static const ZoneInfo kZoneAlmostLosAngeles ACE_TIME_PROGMEM = {
  "Almost_Los_Angeles" /*name*/,
  0x70166020 /*zoneId*/,
  &::kZoneContext /*zoneContext*/,
  3 /*numEras*/,
  kZoneEraAlmostLosAngeles /*eras*/,
};

//---------------------------------------------------------------------------
// A real ZoneInfo for America/Los_Angeles. Taken from zonedbx/zone_infos.cpp.
//---------------------------------------------------------------------------

static const ZoneRule kZoneRulesTestUS[] ACE_TIME_PROGMEM = {
  // Rule    US    1967    2006    -    Oct    lastSun    2:00    0    S
  {
    -33 /*fromYearTiny*/,
    6 /*toYearTiny*/,
    10 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    ZoneContext::kSuffixW /*atTimeModifier*/,
    0 + 4 /*deltaCode*/,
    'S' /*letter*/,
  },
  // Rule    US    1976    1986    -    Apr    lastSun    2:00    1:00    D
  {
    -24 /*fromYearTiny*/,
    -14 /*toYearTiny*/,
    4 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    ZoneContext::kSuffixW /*atTimeModifier*/,
    4 + 4 /*deltaCode*/,
    'D' /*letter*/,
  },
  // Rule    US    1987    2006    -    Apr    Sun>=1    2:00    1:00    D
  {
    -13 /*fromYearTiny*/,
    6 /*toYearTiny*/,
    4 /*inMonth*/,
    7 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    ZoneContext::kSuffixW /*atTimeModifier*/,
    4 + 4 /*deltaCode*/,
    'D' /*letter*/,
  },
  // Rule    US    2007    max    -    Mar    Sun>=8    2:00    1:00    D
  {
    7 /*fromYearTiny*/,
    126 /*toYearTiny*/,
    3 /*inMonth*/,
    7 /*onDayOfWeek*/,
    8 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    ZoneContext::kSuffixW /*atTimeModifier*/,
    4 + 4 /*deltaCode*/,
    'D' /*letter*/,
  },
  // Rule    US    2007    max    -    Nov    Sun>=1    2:00    0    S
  {
    7 /*fromYearTiny*/,
    126 /*toYearTiny*/,
    11 /*inMonth*/,
    7 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    ZoneContext::kSuffixW /*atTimeModifier*/,
    0 + 4 /*deltaCode*/,
    'S' /*letter*/,
  },

};

static const ZonePolicy kPolicyTestUS ACE_TIME_PROGMEM = {
  kZoneRulesTestUS /*rules*/,
  nullptr /* letters */,
  5 /*numRules*/,
  0 /* numLetters */,
};

static const ZoneEra kZoneEraTestLos_Angeles[] ACE_TIME_PROGMEM = {
  //             -8:00    US    P%sT
  {
    &kPolicyTestUS /*zonePolicy*/,
    "P%T" /*format*/,
    -32 /*offsetCode*/,
    0 + 4 /*deltaCode*/,
    127 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    ZoneContext::kSuffixW /*untilTimeModifier*/,
  },

};

static const ZoneInfo kZoneTestLos_Angeles ACE_TIME_PROGMEM = {
  "America/Los_Angeles" /*name*/,
  0xb7f7e8f2 /*zoneId*/,
  &::kZoneContext /*zoneContext*/,
  1 /*numEras*/,
  kZoneEraTestLos_Angeles /*eras*/,
};

//---------------------------------------------------------------------------
// ExtendedZoneProcessor: test private methods
//---------------------------------------------------------------------------

static const ZoneEra era ACE_TIME_PROGMEM =
    {nullptr, "", 0, 0, 0, 1, 2, 12, ZoneContext::kSuffixW};

test(ExtendedZoneProcessorTest, compareEraToYearMonth) {
  assertEqual(1, ExtendedZoneProcessor::compareEraToYearMonth(
      ZoneEraBroker(&era), 0, 1));
  assertEqual(1, ExtendedZoneProcessor::compareEraToYearMonth(
      ZoneEraBroker(&era), 0, 1));
  assertEqual(-1, ExtendedZoneProcessor::compareEraToYearMonth(
      ZoneEraBroker(&era), 0, 2));
  assertEqual(-1, ExtendedZoneProcessor::compareEraToYearMonth(
      ZoneEraBroker(&era), 0, 3));
}

static const ZoneEra era2 ACE_TIME_PROGMEM =
    {nullptr, "", 0, 0, 0, 1, 0, 0, ZoneContext::kSuffixW};

test(ExtendedZoneProcessorTest, compareEraToYearMonth2) {
  assertEqual(0, ExtendedZoneProcessor::compareEraToYearMonth(
      ZoneEraBroker(&era2), 0, 1));
}

// UNTIL = 2000-01-02 3:00
static const ZoneEra prev ACE_TIME_PROGMEM =
    {nullptr, "", 0, 0, 0, 1, 2, 3, ZoneContext::kSuffixW};

// UNTIL = 2002-03-04 5:00
static const ZoneEra era3 ACE_TIME_PROGMEM =
    {nullptr, "", 0, 0, 2, 3, 4, 5, ZoneContext::kSuffixW};

test(ExtendedZoneProcessorTest, createMatch) {
  YearMonthTuple startYm = {0, 12};
  YearMonthTuple untilYm = {1, 2};
  ExtendedZoneProcessor::ZoneMatch match = ExtendedZoneProcessor::createMatch(
      ZoneEraBroker(&prev), ZoneEraBroker(&era3),
      startYm, untilYm);
  assertTrue((match.startDateTime == DateTuple{0, 12, 1, 0,
      ZoneContext::kSuffixW}));
  assertTrue((match.untilDateTime == DateTuple{1, 2, 1, 0,
      ZoneContext::kSuffixW}));
  assertTrue(match.era.equals(ZoneEraBroker(&era3)));

  startYm = {-1, 12};
  untilYm = {3, 2};
  match = ExtendedZoneProcessor::createMatch(
      ZoneEraBroker(&prev), ZoneEraBroker(&era3),
      startYm, untilYm);
  assertTrue((match.startDateTime == DateTuple{0, 1, 2, 15*3,
      ZoneContext::kSuffixW}));
  assertTrue((match.untilDateTime == DateTuple{2, 3, 4, 15*5,
      ZoneContext::kSuffixW}));
  assertTrue(match.era.equals(ZoneEraBroker(&era3)));
}

test(ExtendedZoneProcessorTest, findMatches_simple) {
  YearMonthTuple startYm = {18, 12};
  YearMonthTuple untilYm = {20, 2};
  const uint8_t kMaxMatches = 4;
  ExtendedZoneProcessor::ZoneMatch matches[kMaxMatches];
  uint8_t numMatches = ExtendedZoneProcessor::findMatches(
      ZoneInfoBroker(&kZoneAlmostLosAngeles), startYm, untilYm,
      matches, kMaxMatches);
  assertEqual(3, numMatches);

  assertTrue((matches[0].startDateTime == DateTuple{18, 12, 1, 0,
      ZoneContext::kSuffixW}));
  assertTrue((matches[0].untilDateTime == DateTuple{19, 3, 10, 15*8,
      ZoneContext::kSuffixW}));
  assertTrue(matches[0].era.equals(
      ZoneEraBroker(&kZoneEraAlmostLosAngeles[0])));

  assertTrue((matches[1].startDateTime == DateTuple{19, 3, 10, 15*8,
      ZoneContext::kSuffixW}));
  assertTrue((matches[1].untilDateTime == DateTuple{19, 11, 3, 15*8,
      ZoneContext::kSuffixW}));
  assertTrue(matches[1].era.equals(
      ZoneEraBroker(&kZoneEraAlmostLosAngeles[1])));

  assertTrue((matches[2].startDateTime == DateTuple{19, 11, 3, 15*8,
      ZoneContext::kSuffixW}));
  assertTrue((matches[2].untilDateTime == DateTuple{20, 2, 1, 0,
      ZoneContext::kSuffixW}));
  assertTrue(matches[2].era.equals(
      ZoneEraBroker(&kZoneEraAlmostLosAngeles[2])));
}

test(ExtendedZoneProcessorTest, findMatches_named) {
  YearMonthTuple startYm = {18, 12};
  YearMonthTuple untilYm = {20, 2};
  const uint8_t kMaxMatches = 4;
  ExtendedZoneProcessor::ZoneMatch matches[kMaxMatches];
  uint8_t numMatches = ExtendedZoneProcessor::findMatches(
      ZoneInfoBroker(&kZoneTestLos_Angeles), startYm, untilYm,
      matches, kMaxMatches);
  assertEqual(1, numMatches);

  assertTrue((matches[0].startDateTime == DateTuple{18, 12, 1, 0,
      ZoneContext::kSuffixW}));
  assertTrue((matches[0].untilDateTime == DateTuple{20, 2, 1, 0,
      ZoneContext::kSuffixW}));
  assertTrue(matches[0].era.equals(
      ZoneEraBroker(&kZoneEraTestLos_Angeles[0])));
}

test(ExtendedZoneProcessorTest, getTransitionTime) {
  // Nov Sun>=1
  const auto rule = ZoneRuleBroker(&kZoneRulesTestUS[4]);

  // Nov 4 2018
  DateTuple dt = ExtendedZoneProcessor::getTransitionTime(18, rule);
  assertTrue((dt == DateTuple{18, 11, 4, 15*8, ZoneContext::kSuffixW}));

  // Nov 3 2019
  dt = ExtendedZoneProcessor::getTransitionTime(19, rule);
  assertTrue((dt == DateTuple{19, 11, 3, 15*8, ZoneContext::kSuffixW}));
}

test(ExtendedZoneProcessorTest, createTransitionForYear) {
  const ExtendedZoneProcessor::ZoneMatch match = {
    {18, 12, 1, 0, ZoneContext::kSuffixW},
    {20, 2, 1, 0, ZoneContext::kSuffixW},
    ZoneEraBroker(&kZoneEraTestLos_Angeles[0])
  };
  // Nov Sun>=1
  const auto rule = ZoneRuleBroker(&kZoneRulesTestUS[4]);
  ExtendedZoneProcessor::Transition t;
  ExtendedZoneProcessor::createTransitionForYear(&t, 19, rule, &match);
  assertTrue((t.transitionTime == DateTuple{19, 11, 3, 15*8,
      ZoneContext::kSuffixW}));
}

test(ExtendedZoneProcessorTest, normalizeDateTuple) {
  DateTuple dtp;

  dtp = {0, 1, 1, 0, ZoneContext::kSuffixW};
  ExtendedZoneProcessor::normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{0, 1, 1, 0, ZoneContext::kSuffixW}));

  dtp = {0, 1, 1, 15*95, ZoneContext::kSuffixW}; // 23:45
  ExtendedZoneProcessor::normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{0, 1, 1, 15*95, ZoneContext::kSuffixW}));

  dtp = {0, 1, 1, 15*96, ZoneContext::kSuffixW}; // 24:00
  ExtendedZoneProcessor::normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{0, 1, 2, 0, ZoneContext::kSuffixW}));

  dtp = {0, 1, 1, 15*97, ZoneContext::kSuffixW}; // 24:15
  ExtendedZoneProcessor::normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{0, 1, 2, 15, ZoneContext::kSuffixW}));

  dtp = {0, 1, 1, -15*96, ZoneContext::kSuffixW}; // -24:00
  ExtendedZoneProcessor::normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{-1, 12, 31, 0, ZoneContext::kSuffixW}));

  dtp = {0, 1, 1, -15*97, ZoneContext::kSuffixW}; // -24:15
  ExtendedZoneProcessor::normalizeDateTuple(&dtp);
  assertTrue((dtp == DateTuple{-1, 12, 31, -15, ZoneContext::kSuffixW}));
}

test(ExtendedZoneProcessorTest, expandDateTuple) {
  DateTuple tt;
  DateTuple tts;
  DateTuple ttu;
  int16_t offsetMinutes = 2*60;
  int16_t deltaMinutes = 1*60;

  tt = {0, 1, 30, 15*12, ZoneContext::kSuffixW}; // 03:00
  ExtendedZoneProcessor::expandDateTuple(&tt, &tts, &ttu,
      offsetMinutes, deltaMinutes);
  assertTrue((tt == DateTuple{0, 1, 30, 15*12, ZoneContext::kSuffixW}));
  assertTrue((tts == DateTuple{0, 1, 30, 15*8, ZoneContext::kSuffixS}));
  assertTrue((ttu == DateTuple{0, 1, 30, 0, ZoneContext::kSuffixU}));

  tt = {0, 1, 30, 15*8, ZoneContext::kSuffixS};
  ExtendedZoneProcessor::expandDateTuple(&tt, &tts, &ttu,
      offsetMinutes, deltaMinutes);
  assertTrue((tt == DateTuple{0, 1, 30, 15*12, ZoneContext::kSuffixW}));
  assertTrue((tts == DateTuple{0, 1, 30, 15*8, ZoneContext::kSuffixS}));
  assertTrue((ttu == DateTuple{0, 1, 30, 0, ZoneContext::kSuffixU}));

  tt = {0, 1, 30, 0, ZoneContext::kSuffixU};
  ExtendedZoneProcessor::expandDateTuple(&tt, &tts, &ttu,
      offsetMinutes, deltaMinutes);
  assertTrue((tt == DateTuple{0, 1, 30, 15*12, ZoneContext::kSuffixW}));
  assertTrue((tts == DateTuple{0, 1, 30, 15*8, ZoneContext::kSuffixS}));
  assertTrue((ttu == DateTuple{0, 1, 30, 0, ZoneContext::kSuffixU}));
}

test(ExtendedZoneProcessorTest, calcInteriorYears) {
  const uint8_t kMaxInteriorYears = 4;
  int8_t interiorYears[kMaxInteriorYears];

  uint8_t num = ExtendedZoneProcessor::calcInteriorYears(
      interiorYears, kMaxInteriorYears, -2, -1, 0, 2);
  assertEqual(0, num);

  num = ExtendedZoneProcessor::calcInteriorYears(
      interiorYears, kMaxInteriorYears, 3, 5, 0, 2);
  assertEqual(0, num);

  num = ExtendedZoneProcessor::calcInteriorYears(
      interiorYears, kMaxInteriorYears, -2, 0, 0, 2);
  assertEqual(1, num);
  assertEqual(0, interiorYears[0]);

  num = ExtendedZoneProcessor::calcInteriorYears(
      interiorYears, kMaxInteriorYears, 2, 4, 0, 2);
  assertEqual(1, num);
  assertEqual(2, interiorYears[0]);

  num = ExtendedZoneProcessor::calcInteriorYears(
      interiorYears, kMaxInteriorYears, 1, 2, 0, 2);
  assertEqual(2, num);
  assertEqual(1, interiorYears[0]);
  assertEqual(2, interiorYears[1]);

  num = ExtendedZoneProcessor::calcInteriorYears(
      interiorYears, kMaxInteriorYears, -1, 3, 0, 2);
  assertEqual(3, num);
  assertEqual(0, interiorYears[0]);
  assertEqual(1, interiorYears[1]);
  assertEqual(2, interiorYears[2]);
}

test(ExtendedZoneProcessorTest, getMostRecentPriorYear) {
  int8_t yearTiny;

  yearTiny = ExtendedZoneProcessor::getMostRecentPriorYear(-2, -1, 0, 2);
  assertEqual(-1, yearTiny);

  yearTiny = ExtendedZoneProcessor::getMostRecentPriorYear(3, 5, 0, 2);
  assertEqual(LocalDate::kInvalidYearTiny, yearTiny);

  yearTiny = ExtendedZoneProcessor::getMostRecentPriorYear(-2, 0, 0, 2);
  assertEqual(-1, yearTiny);

  yearTiny = ExtendedZoneProcessor::getMostRecentPriorYear(2, 4, 0, 2);
  assertEqual(LocalDate::kInvalidYearTiny, yearTiny);

  yearTiny = ExtendedZoneProcessor::getMostRecentPriorYear(1, 2, 0, 2);
  assertEqual(LocalDate::kInvalidYearTiny, yearTiny);

  yearTiny = ExtendedZoneProcessor::getMostRecentPriorYear(-1, 3, 0, 2);
  assertEqual(-1, yearTiny);
}

test(ExtendedZoneProcessorTest, compareTransitionToMatchFuzzy) {
  const DateTuple EMPTY_DATE = { 0, 0, 0, 0, 0};

  const ExtendedZoneProcessor::ZoneMatch match = {
    {0, 1, 1, 0, ZoneContext::kSuffixW} /* startDateTime */,
    {1, 1, 1, 0, ZoneContext::kSuffixW} /* untilDateTime */,
    ZoneEraBroker(nullptr)
  };

  ExtendedZoneProcessor::Transition transition = {
    &match /*match*/, ZoneRuleBroker(nullptr) /*rule*/,
    {-1, 11, 1, 0, ZoneContext::kSuffixW} /*transitionTime*/,
    EMPTY_DATE, EMPTY_DATE, EMPTY_DATE, 0, 0, 0, {0}, {0}, false
  };
  assertEqual(-1, ExtendedZoneProcessor::compareTransitionToMatchFuzzy(
      &transition, &match));

  transition = {
    &match /*match*/, ZoneRuleBroker(nullptr) /*rule*/,
    {-1, 12, 1, 0, ZoneContext::kSuffixW} /*transitionTime*/,
    EMPTY_DATE, EMPTY_DATE, EMPTY_DATE, 0, 0, 0, {0}, {0}, false
  };
  assertEqual(1, ExtendedZoneProcessor::compareTransitionToMatchFuzzy(
      &transition, &match));

  transition = {
    &match /*match*/, ZoneRuleBroker(nullptr) /*rule*/,
    {0, 1, 1, 0, ZoneContext::kSuffixW} /*transitionTime*/,
    EMPTY_DATE, EMPTY_DATE, EMPTY_DATE, 0, 0, 0, {0}, {0}, false
  };
  assertEqual(1, ExtendedZoneProcessor::compareTransitionToMatchFuzzy(
      &transition, &match));

  transition = {
    &match /*match*/, ZoneRuleBroker(nullptr) /*rule*/,
    {1, 1, 1, 0, ZoneContext::kSuffixW} /*transitionTime*/,
    EMPTY_DATE, EMPTY_DATE, EMPTY_DATE, 0, 0, 0, {0}, {0}, false
  };
  assertEqual(1, ExtendedZoneProcessor::compareTransitionToMatchFuzzy(
      &transition, &match));

  transition = {
    &match /*match*/, ZoneRuleBroker(nullptr) /*rule*/,
    {1, 2, 1, 0, ZoneContext::kSuffixW} /*transitionTime*/,
    EMPTY_DATE, EMPTY_DATE, EMPTY_DATE, 0, 0, 0, {0}, {0}, false
  };
  assertEqual(1, ExtendedZoneProcessor::compareTransitionToMatchFuzzy(
      &transition, &match));

  transition = {
    &match /*match*/, ZoneRuleBroker(nullptr) /*rule*/,
    {1, 3, 1, 0, ZoneContext::kSuffixW} /*transitionTime*/,
    EMPTY_DATE, EMPTY_DATE, EMPTY_DATE, 0, 0, 0, {0}, {0}, false
  };
  assertEqual(2, ExtendedZoneProcessor::compareTransitionToMatchFuzzy(
      &transition, &match));
}


test(ExtendedZoneProcessorTest, compareTransitionToMatch) {
  const DateTuple EMPTY_DATE = { 0, 0, 0, 0, 0};

  const ExtendedZoneProcessor::ZoneMatch match = {
    {0, 1, 1, 0, ZoneContext::kSuffixW} /*startDateTime*/,
    {1, 1, 1, 0, ZoneContext::kSuffixW} /*untilDateTime*/,
    ZoneEraBroker(nullptr) /*era*/
  };

  ExtendedZoneProcessor::Transition transition = {
    &match /*match*/, ZoneRuleBroker(nullptr) /*rule*/,
    {-1, 12, 31, 0, ZoneContext::kSuffixW} /*transitionTime*/,
    EMPTY_DATE, EMPTY_DATE, EMPTY_DATE, 0, 0, 0, {0}, {0}, false
  };
  assertEqual(-1, ExtendedZoneProcessor::compareTransitionToMatch(
      &transition, &match));

  transition = {
    &match /*match*/, ZoneRuleBroker(nullptr) /*rule*/,
    {0, 1, 1, 0, ZoneContext::kSuffixW} /*transitionTime*/,
    EMPTY_DATE, EMPTY_DATE, EMPTY_DATE, 0, 0, 0, {0}, {0}, false
  };
  assertEqual(0, ExtendedZoneProcessor::compareTransitionToMatch(
      &transition, &match));

  transition = {
    &match /*match*/, ZoneRuleBroker(nullptr) /*rule*/,
    {0, 1, 2, 0, ZoneContext::kSuffixW} /*transitionTime*/,
    EMPTY_DATE, EMPTY_DATE, EMPTY_DATE, 0, 0, 0, {0}, {0}, false
  };
  assertEqual(1, ExtendedZoneProcessor::compareTransitionToMatch(
      &transition, &match));

  transition = {
    &match /*match*/, ZoneRuleBroker(nullptr) /*rule*/,
    {1, 1, 2, 0, ZoneContext::kSuffixW} /*transitionTime*/,
    EMPTY_DATE, EMPTY_DATE, EMPTY_DATE, 0, 0, 0, {0}, {0}, false
  };
  assertEqual(2, ExtendedZoneProcessor::compareTransitionToMatch(
      &transition, &match));
}

test(ExtendedZoneProcessorTest, processActiveTransition) {
  const DateTuple EMPTY_DATE = { 0, 0, 0, 0, 0};

  ExtendedZoneProcessor::Transition* prior = nullptr;
  const ExtendedZoneProcessor::ZoneMatch match = {
    {0, 1, 1, 0, ZoneContext::kSuffixW} /*startDateTime*/,
    {1, 1, 1, 0, ZoneContext::kSuffixW} /*untilDateTime*/,
    ZoneEraBroker(nullptr) /*era*/
  };

  // This transition occurs before the match, so prior should be filled.
  ExtendedZoneProcessor::Transition transition0 = {
    &match /*match*/, ZoneRuleBroker(nullptr) /*rule*/,
    {-1, 12, 31, 0, ZoneContext::kSuffixW} /*transitionTime*/,
    EMPTY_DATE, EMPTY_DATE, EMPTY_DATE, 0, 0, 0, {0}, {0}, false
  };
  ExtendedZoneProcessor::processActiveTransition(&match, &transition0, &prior);
  assertTrue(transition0.active);
  assertTrue(prior == &transition0);

  // This occurs at exactly match.startDateTime, so should replace
  ExtendedZoneProcessor::Transition transition1 = {
    &match /*match*/, ZoneRuleBroker(nullptr) /*rule*/,
    {0, 1, 1, 0, ZoneContext::kSuffixW} /*transitionTime*/,
    EMPTY_DATE, EMPTY_DATE, EMPTY_DATE, 0, 0, 0, {0}, {0}, false
  };
  ExtendedZoneProcessor::processActiveTransition(&match, &transition1, &prior);
  assertTrue(transition1.active);
  assertTrue(prior == &transition1);

  // An interior transition. Prior should not change.
  ExtendedZoneProcessor::Transition transition2 = {
    &match /*match*/, ZoneRuleBroker(nullptr) /*rule*/,
    {0, 1, 2, 0, ZoneContext::kSuffixW} /*transitionTime*/,
    EMPTY_DATE, EMPTY_DATE, EMPTY_DATE, 0, 0, 0, {0}, {0}, false
  };
  ExtendedZoneProcessor::processActiveTransition(&match, &transition2, &prior);
  assertTrue(transition2.active);
  assertTrue(prior == &transition1);

  // Occurs after match.untilDateTime, so should be rejected.
  ExtendedZoneProcessor::Transition transition3 = {
    &match /*match*/, ZoneRuleBroker(nullptr) /*rule*/,
    {1, 1, 2, 0, ZoneContext::kSuffixW} /*transitionTime*/,
    EMPTY_DATE, EMPTY_DATE, EMPTY_DATE, 0, 0, 0, {0}, {0}, false
  };
  assertFalse(transition3.active);
  assertTrue(prior == &transition1);
}

test(ExtendedZoneProcessorTest, findCandidateTransitions) {
  const ExtendedZoneProcessor::ZoneMatch match = {
    {18, 12, 1, 0, ZoneContext::kSuffixW},
    {20, 2, 1, 0, ZoneContext::kSuffixW},
    ZoneEraBroker(&kZoneEraTestLos_Angeles[0])
  };

  // Reserve storage for the Transitions
  ExtendedZoneProcessor::TransitionStorage storage;
  storage.init();

  // Verify compareTransitionToMatchFuzzy() elminates various transitions
  // to get down to 5:
  //    * 2018 Mar Sun>=8 (11)
  //    * 2019 Nov Sun>=1 (4)
  //    * 2019 Mar Sun>=8 (10)
  //    * 2019 Nov Sun>=1 (3)
  //    * 2020 Mar Sun>=8 (8)
  storage.resetCandidatePool();
  ExtendedZoneProcessor::findCandidateTransitions(storage, &match);
  assertEqual(5,
      (int) (storage.getCandidatePoolEnd() - storage.getCandidatePoolBegin()));
  ExtendedZoneProcessor::Transition** t = storage.getCandidatePoolBegin();
  assertTrue(((*t++)->transitionTime == DateTuple{18, 3, 11, 15*8,
      ZoneContext::kSuffixW}));
  assertTrue(((*t++)->transitionTime == DateTuple{18, 11, 4, 15*8,
      ZoneContext::kSuffixW}));
  assertTrue(((*t++)->transitionTime == DateTuple{19, 3, 10, 15*8,
      ZoneContext::kSuffixW}));
  assertTrue(((*t++)->transitionTime == DateTuple{19, 11, 3, 15*8,
      ZoneContext::kSuffixW}));
  assertTrue(((*t++)->transitionTime == DateTuple{20, 3, 8, 15*8,
      ZoneContext::kSuffixW}));
}

test(ExtendedZoneProcessorTest, findTransitionsFromNamedMatch) {
  const ExtendedZoneProcessor::ZoneMatch match = {
    {18, 12, 1, 0, ZoneContext::kSuffixW},
    {20, 2, 1, 0, ZoneContext::kSuffixW},
    ZoneEraBroker(&kZoneEraTestLos_Angeles[0])
  };

  // Reserve storage for the Transitions
  ExtendedZoneProcessor::TransitionStorage storage;
  storage.init();

  ExtendedZoneProcessor::findTransitionsFromNamedMatch(storage, &match);
  assertEqual(3,
      (int) (storage.getActivePoolEnd() - storage.getActivePoolBegin()));
  ExtendedZoneProcessor::Transition** t = storage.getActivePoolBegin();
  assertTrue(((*t++)->transitionTime == DateTuple{18, 12, 1, 0,
      ZoneContext::kSuffixW}));
  assertTrue(((*t++)->transitionTime == DateTuple{19, 3, 10, 15*8,
      ZoneContext::kSuffixW}));
  assertTrue(((*t++)->transitionTime == DateTuple{19, 11, 3, 15*8,
      ZoneContext::kSuffixW}));
}

test(ExtendedZoneProcessorTest, fixTransitionTimes_generateStartUntilTimes) {
  // Create 3 matches for the AlmostLosAngeles test zone.
  YearMonthTuple startYm = {18, 12};
  YearMonthTuple untilYm = {20, 2};
  const uint8_t kMaxMatches = 4;
  ExtendedZoneProcessor::ZoneMatch matches[kMaxMatches];
  uint8_t numMatches = ExtendedZoneProcessor::findMatches(
      ZoneInfoBroker(&kZoneAlmostLosAngeles), startYm, untilYm,
      matches, kMaxMatches);
  assertEqual(3, numMatches);

  // Create a custom template instantiation to use a different SIZE than the
  // pre-defined typedef in ExtendedZoneProcess::TransitionStorage.
  TransitionStorageTemplate<
      4 /*SIZE*/,
      ZoneEraBroker,
      ZonePolicyBroker,
      ZoneRuleBroker> storage;
  storage.init();

  // Create 3 Transitions corresponding to the matches.
  // Implements ExtendedZoneProcessor::findTransitionsFromSimpleMatch().
  ExtendedZoneProcessor::Transition* transition1 = storage.getFreeAgent();
  ExtendedZoneProcessor::createTransitionForYear(
      transition1, 0 /*not used*/, ZoneRuleBroker(nullptr) /*rule*/,
      &matches[0]);
  transition1->active = true;
  storage.addFreeAgentToCandidatePool();

  ExtendedZoneProcessor::Transition* transition2 = storage.getFreeAgent();
  ExtendedZoneProcessor::createTransitionForYear(
      transition2, 0 /*not used*/, ZoneRuleBroker(nullptr) /*rule*/,
      &matches[1]);
  transition2->active = true;
  storage.addFreeAgentToCandidatePool();

  ExtendedZoneProcessor::Transition* transition3 = storage.getFreeAgent();
  ExtendedZoneProcessor::createTransitionForYear(
      transition3, 0 /*not used*/, ZoneRuleBroker(nullptr) /*rule*/,
      &matches[2]);
  transition3->active = true;
  storage.addFreeAgentToCandidatePool();

  // Move actives to Active pool.
  storage.addActiveCandidatesToActivePool();
  ExtendedZoneProcessor::Transition** begin = storage.getActivePoolBegin();
  ExtendedZoneProcessor::Transition** end = storage.getActivePoolEnd();
  assertEqual(3, (int) (end - begin));
  assertTrue(begin[0] == transition1);
  assertTrue(begin[1] == transition2);
  assertTrue(begin[2] == transition3);

  // Fix the transition times, expanding to 's' and 'u'
  ExtendedZoneProcessor::fixTransitionTimes(begin, end);

  // Verify. The first Transition is extended to -infinity.
  assertTrue((transition1->transitionTime == DateTuple{18, 12, 1, 0,
      ZoneContext::kSuffixW}));
  assertTrue((transition1->transitionTimeS == DateTuple{18, 12, 1, 0,
      ZoneContext::kSuffixS}));
  assertTrue((transition1->transitionTimeU == DateTuple{18, 12, 1, 15*32,
      ZoneContext::kSuffixU}));

  // Second transition uses the UTC offset of the first.
  assertTrue((transition2->transitionTime == DateTuple{19, 3, 10, 15*8,
      ZoneContext::kSuffixW}));
  assertTrue((transition2->transitionTimeS == DateTuple{19, 3, 10, 15*8,
      ZoneContext::kSuffixS}));
  assertTrue((transition2->transitionTimeU == DateTuple{19, 3, 10, 15*40,
      ZoneContext::kSuffixU}));

  // Third transition uses the UTC offset of the second.
  assertTrue((transition3->transitionTime == DateTuple{19, 11, 3, 15*8,
      ZoneContext::kSuffixW}));
  assertTrue((transition3->transitionTimeS == DateTuple{19, 11, 3, 15*4,
      ZoneContext::kSuffixS}));
  assertTrue((transition3->transitionTimeU == DateTuple{19, 11, 3, 15*36,
      ZoneContext::kSuffixU}));

  // Generate the startDateTime and untilDateTime of the transitions.
  ExtendedZoneProcessor::generateStartUntilTimes(begin, end);

  // Verify. The first transition startTime should be the same as its
  // transitionTime.
  assertTrue((transition1->transitionTime == DateTuple{18, 12, 1, 0,
      ZoneContext::kSuffixW}));
  assertTrue((transition1->startDateTime == DateTuple{18, 12, 1, 0,
      ZoneContext::kSuffixW}));
  assertTrue((transition1->untilDateTime == DateTuple{19, 3, 10, 15*8,
      ZoneContext::kSuffixW}));
  acetime_t epochSecs = OffsetDateTime::forComponents(
      2018, 12, 1, 0, 0, 0, TimeOffset::forHours(-8)).toEpochSeconds();
  assertEqual(epochSecs, transition1->startEpochSeconds);

  // Second transition startTime is shifted forward one hour into PDT.
  assertTrue((transition2->transitionTime == DateTuple{19, 3, 10, 15*8,
      ZoneContext::kSuffixW}));
  assertTrue((transition2->startDateTime == DateTuple{19, 3, 10, 15*12,
      ZoneContext::kSuffixW}));
  assertTrue((transition2->untilDateTime == DateTuple{19, 11, 3, 15*8,
      ZoneContext::kSuffixW}));
  epochSecs = OffsetDateTime::forComponents(
      2019, 3, 10, 3, 0, 0, TimeOffset::forHours(-7)).toEpochSeconds();
  assertEqual(epochSecs, transition2->startEpochSeconds);

  // Third transition startTime is shifted back one hour into PST.
  assertTrue((transition3->transitionTime == DateTuple{19, 11, 3, 15*8,
      ZoneContext::kSuffixW}));
  assertTrue((transition3->startDateTime == DateTuple{19, 11, 3, 15*4,
      ZoneContext::kSuffixW}));
  assertTrue((transition3->untilDateTime == DateTuple{20, 2, 1, 0,
      ZoneContext::kSuffixW}));
  epochSecs = OffsetDateTime::forComponents(
      2019, 11, 3, 1, 0, 0, TimeOffset::forHours(-8)).toEpochSeconds();
  assertEqual(epochSecs, transition3->startEpochSeconds);
}

test(ExtendedZoneProcessorTest, createAbbreviation) {
  const uint8_t kDstSize = 6;
  char dst[kDstSize];

  // If no '%', deltaMinutes and letter should not matter
  ExtendedZoneProcessor::createAbbreviation(dst, kDstSize, "SAST", 0, nullptr);
  assertEqual("SAST", dst);

  ExtendedZoneProcessor::createAbbreviation(dst, kDstSize, "SAST", 60, "A");
  assertEqual("SAST", dst);

  // If '%', and letter is (incorrectly) set to '\0', just copy the thing
  ExtendedZoneProcessor::createAbbreviation(dst, kDstSize, "SA%ST", 0, nullptr);
  assertEqual("SA%ST", dst);

  // If '%', then replaced with (non-null) letterString.
  ExtendedZoneProcessor::createAbbreviation(dst, kDstSize, "P%T", 60, "D");
  assertEqual("PDT", dst);

  ExtendedZoneProcessor::createAbbreviation(dst, kDstSize, "P%T", 0, "S");
  assertEqual("PST", dst);

  ExtendedZoneProcessor::createAbbreviation(dst, kDstSize, "P%T", 0, "");
  assertEqual("PT", dst);

  ExtendedZoneProcessor::createAbbreviation(dst, kDstSize, "%", 60, "CAT");
  assertEqual("CAT", dst);

  ExtendedZoneProcessor::createAbbreviation(dst, kDstSize, "%", 0, "WAT");
  assertEqual("WAT", dst);

  // If '/', then deltaMinutes selects the first or second component.
  ExtendedZoneProcessor::createAbbreviation(dst, kDstSize, "GMT/BST", 0, "");
  assertEqual("GMT", dst);

  ExtendedZoneProcessor::createAbbreviation(dst, kDstSize, "GMT/BST", 60, "");
  assertEqual("BST", dst);

  // test truncation to kDstSize
  ExtendedZoneProcessor::createAbbreviation(dst, kDstSize, "P%T3456", 60, "DD");
  assertEqual("PDDT3", dst);
}

test(ExtendedZoneProcessorTest, calcAbbreviations) {
  // TODO: Implement
}

//---------------------------------------------------------------------------

void setup() {
#if ! defined(EPOXY_DUINO)
  delay(1000); // wait to prevent garbage on SERIAL_PORT_MONITOR
#endif
  SERIAL_PORT_MONITOR.begin(115200);
  while (!SERIAL_PORT_MONITOR); // Leonardo/Micro

#if 0
  TestRunner::exclude("*");
  TestRunner::include("ExtendedZoneProcessorTest",
      "findTransitionsFromNamedMatch");
#endif
}

void loop() {
  TestRunner::run();
}
