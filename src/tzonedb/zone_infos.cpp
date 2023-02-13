// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/tzonedb/tzfiles
//     --output_dir /home/brian/src/AceTime/src/tzonedb
//     --tz_version 2022g
//     --action zonedb
//     --language arduino
//     --scope basic
//     --db_namespace tzonedb
//     --generate_int16_years
//     --include_list include_list.txt
//     --nocompress
//     --start_year 1980
//     --until_year 10000
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
// from https://github.com/eggert/tz/releases/tag/2022g
//
// Supported Zones: 12 (11 zones, 1 links)
// Unsupported Zones: 584 (340 zones, 244 links)
// Original Years: [1844,2087]
// Generated Years: [1943,2007]
//
// Zones: 11
// Links: 1
// kZoneRegistry sizes (bytes):
//   Names: 191 (originally 191)
//   Formats: 38
//   Fragments: 9
//   Memory (8-bit): 587
//   Memory (32-bit): 790
// kZoneAndLinkRegistry sizes (bytes):
//   Names: 202 (originally 202)
//   Formats: 38
//   Fragments: 9
//   Memory (8-bit): 613
//   Memory (32-bit): 829
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

const char kTzDatabaseVersion[] = "2022g";

const char* const kFragments[] = {
/*\x00*/ nullptr,
/*\x01*/ "America/",

};

const char* const kLetters[] = {
/*0*/ "",
/*1*/ "D",
/*2*/ "S",

};

const internal::ZoneContext kZoneContext = {
  1980 /*startYear*/,
  10000 /*untilYear*/,
  kTzDatabaseVersion /*tzVersion*/,
  2 /*numFragments*/,
  3 /*numLetters*/,
  kFragments /*fragments*/,
  kLetters /*letters*/,
};

//---------------------------------------------------------------------------
// Zones: 11
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Zone name: Africa/Johannesburg
// Zone Eras: 1
// Strings (bytes): 25 (originally 25)
// Memory (8-bit): 50
// Memory (32-bit): 65
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAfrica_Johannesburg[] ACE_TIME_PROGMEM = {
  //             2:00    SA    SAST
  {
    &kZonePolicySA /*zonePolicy*/,
    "SAST" /*format*/,
    8 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    10000 /*untilYear*/,
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
// Zone Eras: 1
// Strings (bytes): 20 (originally 20)
// Memory (8-bit): 45
// Memory (32-bit): 60
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_Chicago[] ACE_TIME_PROGMEM = {
  //             -6:00    US    C%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "C%T" /*format*/,
    -24 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    10000 /*untilYear*/,
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
// Zone Eras: 1
// Strings (bytes): 19 (originally 19)
// Memory (8-bit): 44
// Memory (32-bit): 59
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_Denver[] ACE_TIME_PROGMEM = {
  //             -7:00    US    M%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "M%T" /*format*/,
    -28 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    10000 /*untilYear*/,
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
// Zone Eras: 2
// Strings (bytes): 25 (originally 25)
// Memory (8-bit): 62
// Memory (32-bit): 81
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_Edmonton[] ACE_TIME_PROGMEM = {
  //             -7:00    Edm    M%sT    1987
  {
    &kZonePolicyEdm /*zonePolicy*/,
    "M%T" /*format*/,
    -28 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    1987 /*untilYear*/,
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
    10000 /*untilYear*/,
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
// Zone Eras: 1
// Strings (bytes): 24 (originally 24)
// Memory (8-bit): 49
// Memory (32-bit): 64
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_Los_Angeles[] ACE_TIME_PROGMEM = {
  //             -8:00    US    P%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "P%T" /*format*/,
    -32 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    10000 /*untilYear*/,
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
// Zone Eras: 1
// Strings (bytes): 21 (originally 21)
// Memory (8-bit): 46
// Memory (32-bit): 61
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_New_York[] ACE_TIME_PROGMEM = {
  //             -5:00    US    E%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "E%T" /*format*/,
    -20 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    10000 /*untilYear*/,
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
// Zone Eras: 1
// Strings (bytes): 20 (originally 20)
// Memory (8-bit): 45
// Memory (32-bit): 60
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_Toronto[] ACE_TIME_PROGMEM = {
  //             -5:00    Canada    E%sT
  {
    &kZonePolicyCanada /*zonePolicy*/,
    "E%T" /*format*/,
    -20 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    10000 /*untilYear*/,
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
// Zone Eras: 2
// Strings (bytes): 26 (originally 26)
// Memory (8-bit): 63
// Memory (32-bit): 82
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_Vancouver[] ACE_TIME_PROGMEM = {
  //             -8:00    Vanc    P%sT    1987
  {
    &kZonePolicyVanc /*zonePolicy*/,
    "P%T" /*format*/,
    -32 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    1987 /*untilYear*/,
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
    10000 /*untilYear*/,
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
// Zone Eras: 2
// Strings (bytes): 25 (originally 25)
// Memory (8-bit): 62
// Memory (32-bit): 81
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAmerica_Winnipeg[] ACE_TIME_PROGMEM = {
  //             -6:00    Winn    C%sT    2006
  {
    &kZonePolicyWinn /*zonePolicy*/,
    "C%T" /*format*/,
    -24 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    2006 /*untilYear*/,
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
    10000 /*untilYear*/,
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
// Zone Eras: 1
// Strings (bytes): 22 (originally 22)
// Memory (8-bit): 47
// Memory (32-bit): 62
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraAustralia_Darwin[] ACE_TIME_PROGMEM = {
  //              9:30    Aus    AC%sT
  {
    &kZonePolicyAus /*zonePolicy*/,
    "AC%T" /*format*/,
    38 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    10000 /*untilYear*/,
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
// Zone Eras: 2
// Strings (bytes): 30 (originally 30)
// Memory (8-bit): 67
// Memory (32-bit): 86
//---------------------------------------------------------------------------

static const basic::ZoneEra kZoneEraPacific_Galapagos[] ACE_TIME_PROGMEM = {
  //             -5:00    -    -05    1986
  {
    nullptr /*zonePolicy*/,
    "-05" /*format*/,
    -20 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    1986 /*untilYear*/,
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
    10000 /*untilYear*/,
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
// Strings (bytes): 11 (originally 11)
// Memory (8-bit): 24
// Memory (32-bit): 35
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
