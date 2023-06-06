// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/tzonedb/tzfiles
//     --output_dir /home/brian/src/AceTime/src/tzonedb
//     --tz_version 2023c
//     --action zonedb
//     --language arduino
//     --scope basic
//     --db_namespace tzonedb
//     --include_list include_list.txt
//     --nocompress
//     --start_year 1980
//     --until_year 2200
//
// using the TZ Database files
//
//   africa
//   antarctica
//   asia
//   australasia
//   backward
//   etcetera
//   europe
//   northamerica
//   southamerica
//
// from https://github.com/eggert/tz/releases/tag/2023c
//
// Supported Zones: 12 (11 zones, 1 links)
// Unsupported Zones: 584 (339 zones, 245 links)
//
// Original Years:  [1844,2087]
// Generated Years: [1945,2007]
// Estimator Years: [1945,2009]
// Max Buffer Size: 6
//
// Records:
//   Rules: 32
//   Policies: 8
//   Eras: 15
//   Infos: 12
//
// Memory (8-bits):
//   Rules: 16
//   Rules: 288
//   Policies: 24
//   Eras: 165
//   Zones: 143
//   Links: 13
//   Registry: 24
//   Formats: 38
//   Letters: 11
//   Fragments: 0
//   Names: 202 (original: 202)
//   TOTAL: 924
//
// Memory (32-bits):
//   Rules: 24
//   Rules: 384
//   Policies: 64
//   Eras: 240
//   Zones: 264
//   Links: 24
//   Registry: 48
//   Formats: 38
//   Letters: 17
//   Fragments: 0
//   Names: 202 (original: 202)
//   TOTAL: 1305
//
// DO NOT EDIT

#include <zoneinfo/compat.h>
#include "zone_policies.h"
#include "zone_infos.h"

namespace ace_time {
namespace tzonedb {

//---------------------------------------------------------------------------
// ZoneContext (should not be in PROGMEM)
//---------------------------------------------------------------------------

const char kTzDatabaseVersion[] = "2023c";

const char* const kFragments[] = {
/*\x00*/ nullptr,

};

const char* const kLetters[] = {
/*0*/ "",
/*1*/ "D",
/*2*/ "S",

};

const basic::ZoneContext kZoneContext = {
  1980 /*startYear*/,
  2200 /*untilYear*/,
  2100 /*baseYear*/,
  6 /*maxTransitions*/,
  kTzDatabaseVersion /*tzVersion*/,
  1 /*numFragments*/,
  3 /*numLetters*/,
  kFragments /*fragments*/,
  kLetters /*letters*/,
};

//---------------------------------------------------------------------------
// Zones: 11
// Eras: 15
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Zone name: Africa/Johannesburg
// Eras: 1
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAfrica_Johannesburg[] ACE_TIME_PROGMEM = {
  //             2:00    SA    SAST
  {
    &kZonePolicySA /*zonePolicy*/,
    "SAST" /*format*/,
    8 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    127 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAfrica_Johannesburg[] ACE_TIME_PROGMEM = "Africa/Johannesburg";

const basic::ZoneInfo kZoneAfrica_Johannesburg ACE_TIME_PROGMEM = {
  kZoneNameAfrica_Johannesburg /*name*/,
  0xd5d157a0 /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  1 /*numEras*/,
  kZoneEraAfrica_Johannesburg /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: America/Chicago
// Eras: 1
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_Chicago[] ACE_TIME_PROGMEM = {
  //             -6:00    US    C%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "C%T" /*format*/,
    -24 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    127 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Chicago[] ACE_TIME_PROGMEM = "America/Chicago";

const basic::ZoneInfo kZoneAmerica_Chicago ACE_TIME_PROGMEM = {
  kZoneNameAmerica_Chicago /*name*/,
  0x4b92b5d4 /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  1 /*numEras*/,
  kZoneEraAmerica_Chicago /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: America/Denver
// Eras: 1
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_Denver[] ACE_TIME_PROGMEM = {
  //             -7:00    US    M%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "M%T" /*format*/,
    -28 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    127 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Denver[] ACE_TIME_PROGMEM = "America/Denver";

const basic::ZoneInfo kZoneAmerica_Denver ACE_TIME_PROGMEM = {
  kZoneNameAmerica_Denver /*name*/,
  0x97d10b2a /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  1 /*numEras*/,
  kZoneEraAmerica_Denver /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: America/Edmonton
// Eras: 2
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_Edmonton[] ACE_TIME_PROGMEM = {
  //             -7:00    Edm    M%sT    1987
  {
    &kZonePolicyEdm /*zonePolicy*/,
    "M%T" /*format*/,
    -28 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    -113 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },
  //             -7:00    Canada    M%sT
  {
    &kZonePolicyCanada /*zonePolicy*/,
    "M%T" /*format*/,
    -28 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    127 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Edmonton[] ACE_TIME_PROGMEM = "America/Edmonton";

const basic::ZoneInfo kZoneAmerica_Edmonton ACE_TIME_PROGMEM = {
  kZoneNameAmerica_Edmonton /*name*/,
  0x6cb9484a /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  2 /*numEras*/,
  kZoneEraAmerica_Edmonton /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: America/Los_Angeles
// Eras: 1
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_Los_Angeles[] ACE_TIME_PROGMEM = {
  //             -8:00    US    P%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "P%T" /*format*/,
    -32 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    127 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Los_Angeles[] ACE_TIME_PROGMEM = "America/Los_Angeles";

const basic::ZoneInfo kZoneAmerica_Los_Angeles ACE_TIME_PROGMEM = {
  kZoneNameAmerica_Los_Angeles /*name*/,
  0xb7f7e8f2 /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  1 /*numEras*/,
  kZoneEraAmerica_Los_Angeles /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: America/New_York
// Eras: 1
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_New_York[] ACE_TIME_PROGMEM = {
  //             -5:00    US    E%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "E%T" /*format*/,
    -20 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    127 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_New_York[] ACE_TIME_PROGMEM = "America/New_York";

const basic::ZoneInfo kZoneAmerica_New_York ACE_TIME_PROGMEM = {
  kZoneNameAmerica_New_York /*name*/,
  0x1e2a7654 /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  1 /*numEras*/,
  kZoneEraAmerica_New_York /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: America/Toronto
// Eras: 1
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_Toronto[] ACE_TIME_PROGMEM = {
  //             -5:00    Canada    E%sT
  {
    &kZonePolicyCanada /*zonePolicy*/,
    "E%T" /*format*/,
    -20 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    127 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Toronto[] ACE_TIME_PROGMEM = "America/Toronto";

const basic::ZoneInfo kZoneAmerica_Toronto ACE_TIME_PROGMEM = {
  kZoneNameAmerica_Toronto /*name*/,
  0x792e851b /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  1 /*numEras*/,
  kZoneEraAmerica_Toronto /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: America/Vancouver
// Eras: 2
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_Vancouver[] ACE_TIME_PROGMEM = {
  //             -8:00    Vanc    P%sT    1987
  {
    &kZonePolicyVanc /*zonePolicy*/,
    "P%T" /*format*/,
    -32 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    -113 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },
  //             -8:00    Canada    P%sT
  {
    &kZonePolicyCanada /*zonePolicy*/,
    "P%T" /*format*/,
    -32 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    127 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Vancouver[] ACE_TIME_PROGMEM = "America/Vancouver";

const basic::ZoneInfo kZoneAmerica_Vancouver ACE_TIME_PROGMEM = {
  kZoneNameAmerica_Vancouver /*name*/,
  0x2c6f6b1f /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  2 /*numEras*/,
  kZoneEraAmerica_Vancouver /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: America/Winnipeg
// Eras: 2
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_Winnipeg[] ACE_TIME_PROGMEM = {
  //             -6:00    Winn    C%sT    2006
  {
    &kZonePolicyWinn /*zonePolicy*/,
    "C%T" /*format*/,
    -24 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    -94 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },
  //             -6:00    Canada    C%sT
  {
    &kZonePolicyCanada /*zonePolicy*/,
    "C%T" /*format*/,
    -24 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    127 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Winnipeg[] ACE_TIME_PROGMEM = "America/Winnipeg";

const basic::ZoneInfo kZoneAmerica_Winnipeg ACE_TIME_PROGMEM = {
  kZoneNameAmerica_Winnipeg /*name*/,
  0x8c7dafc7 /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  2 /*numEras*/,
  kZoneEraAmerica_Winnipeg /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: Australia/Darwin
// Eras: 1
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAustralia_Darwin[] ACE_TIME_PROGMEM = {
  //              9:30    Aus    AC%sT
  {
    &kZonePolicyAus /*zonePolicy*/,
    "AC%T" /*format*/,
    38 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    127 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAustralia_Darwin[] ACE_TIME_PROGMEM = "Australia/Darwin";

const basic::ZoneInfo kZoneAustralia_Darwin ACE_TIME_PROGMEM = {
  kZoneNameAustralia_Darwin /*name*/,
  0x2876bdff /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  1 /*numEras*/,
  kZoneEraAustralia_Darwin /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: Pacific/Galapagos
// Eras: 2
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraPacific_Galapagos[] ACE_TIME_PROGMEM = {
  //             -5:00    -    -05    1986
  {
    nullptr /*zonePolicy*/,
    "-05" /*format*/,
    -20 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    -114 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },
  //             -6:00    Ecuador    -06/-05
  {
    &kZonePolicyEcuador /*zonePolicy*/,
    "-06/-05" /*format*/,
    -24 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    127 /*untilYearTiny*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNamePacific_Galapagos[] ACE_TIME_PROGMEM = "Pacific/Galapagos";

const basic::ZoneInfo kZonePacific_Galapagos ACE_TIME_PROGMEM = {
  kZoneNamePacific_Galapagos /*name*/,
  0xa952f752 /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  2 /*numEras*/,
  kZoneEraPacific_Galapagos /*eras*/,
  nullptr /*targetInfo*/,
};



//---------------------------------------------------------------------------
// Links: 1
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Link name: US/Pacific -> America/Los_Angeles
//---------------------------------------------------------------------------

static const char kZoneNameUS_Pacific[] ACE_TIME_PROGMEM = "US/Pacific";

const basic::ZoneInfo kZoneUS_Pacific ACE_TIME_PROGMEM = {
  kZoneNameUS_Pacific /*name*/,
  0xa950f6ab /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  1 /*numEras*/,
  kZoneEraAmerica_Los_Angeles /*eras*/,
  &kZoneAmerica_Los_Angeles /*targetInfo*/,
};


}
}
