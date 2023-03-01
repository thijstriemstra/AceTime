// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/tzonedbx/tzfiles
//     --output_dir /home/brian/src/AceTime/src/tzonedbx
//     --tz_version 2022g
//     --action zonedb
//     --language arduino
//     --scope extended
//     --db_namespace tzonedbx
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
// Supported Zones: 16 (15 zones, 1 links)
// Unsupported Zones: 580 (336 zones, 244 links)
// Original Years: [1844,2087]
// Generated Years: [1945,2087]
//
// Memory (8-bits):
//   Rules: 2464
//   Policies: 36
//   Eras: 360
//   Zones: 195
//   Links: 13
//   Registry: 32
//   Formats: 92
//   Letters: 23
//   Fragments: 0
//   Names: 260 (original: 260)
//   TOTAL: 3475
//
// Memory (32-bits):
//   Rules: 2688
//   Policies: 96
//   Eras: 480
//   Zones: 360
//   Links: 24
//   Registry: 64
//   Formats: 92
//   Letters: 33
//   Fragments: 0
//   Names: 260 (original: 260)
//   TOTAL: 4097
//
// DO NOT EDIT

#include <zoneinfo/compat.h>
#include "zone_policies.h"
#include "zone_infos.h"

namespace ace_time {
namespace tzonedbx {

//---------------------------------------------------------------------------
// ZoneContext (should not be in PROGMEM)
//---------------------------------------------------------------------------

const char kTzDatabaseVersion[] = "2022g";

const char* const kFragments[] = {
/*\x00*/ nullptr,

};

const char* const kLetters[] = {
/*0*/ "",
/*1*/ "CAT",
/*2*/ "D",
/*3*/ "S",
/*4*/ "WAT",

};

const internal::ZoneContext kZoneContext = {
  1980 /*startYear*/,
  10000 /*untilYear*/,
  7 /*maxTransitions*/,
  kTzDatabaseVersion /*tzVersion*/,
  1 /*numFragments*/,
  5 /*numLetters*/,
  kFragments /*fragments*/,
  kLetters /*letters*/,
};

//---------------------------------------------------------------------------
// Zones: 15
// Eras: 30
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Zone name: Africa/Casablanca
// Eras: 4
//---------------------------------------------------------------------------

static const extended::ZoneEra kZoneEraAfrica_Casablanca[] ACE_TIME_PROGMEM = {
  //              0:00    Morocco    +00/+01    1984 Mar 16
  {
    &kZonePolicyMorocco /*zonePolicy*/,
    "+00/+01" /*format*/,
    0 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    1984 /*untilYear*/,
    3 /*untilMonth*/,
    16 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },
  //              1:00    -    +01    1986
  {
    nullptr /*zonePolicy*/,
    "+01" /*format*/,
    4 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    1986 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },
  //              0:00    Morocco    +00/+01    2018 Oct 28  3:00
  {
    &kZonePolicyMorocco /*zonePolicy*/,
    "+00/+01" /*format*/,
    0 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    2018 /*untilYear*/,
    10 /*untilMonth*/,
    28 /*untilDay*/,
    12 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },
  //              1:00    Morocco    +01/+00
  {
    &kZonePolicyMorocco /*zonePolicy*/,
    "+01/+00" /*format*/,
    4 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAfrica_Casablanca[] ACE_TIME_PROGMEM = "Africa/Casablanca";

const extended::ZoneInfo kZoneAfrica_Casablanca ACE_TIME_PROGMEM = {
  kZoneNameAfrica_Casablanca /*name*/,
  0xc59f1b33 /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  4 /*numEras*/,
  kZoneEraAfrica_Casablanca /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: Africa/Windhoek
// Eras: 2
//---------------------------------------------------------------------------

static const extended::ZoneEra kZoneEraAfrica_Windhoek[] ACE_TIME_PROGMEM = {
  //             2:00    -    SAST    1990 Mar 21
  {
    nullptr /*zonePolicy*/,
    "SAST" /*format*/,
    8 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    1990 /*untilYear*/,
    3 /*untilMonth*/,
    21 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },
  //             2:00    Namibia    %s
  {
    &kZonePolicyNamibia /*zonePolicy*/,
    "%" /*format*/,
    8 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAfrica_Windhoek[] ACE_TIME_PROGMEM = "Africa/Windhoek";

const extended::ZoneInfo kZoneAfrica_Windhoek ACE_TIME_PROGMEM = {
  kZoneNameAfrica_Windhoek /*name*/,
  0x789c9bd3 /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  2 /*numEras*/,
  kZoneEraAfrica_Windhoek /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: America/Caracas
// Eras: 3
//---------------------------------------------------------------------------

static const extended::ZoneEra kZoneEraAmerica_Caracas[] ACE_TIME_PROGMEM = {
  //             -4:00    -    -04    2007 Dec  9  3:00
  {
    nullptr /*zonePolicy*/,
    "-04" /*format*/,
    -16 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    2007 /*untilYear*/,
    12 /*untilMonth*/,
    9 /*untilDay*/,
    12 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },
  //             -4:30    -    -0430    2016 May  1  2:30
  {
    nullptr /*zonePolicy*/,
    "-0430" /*format*/,
    -18 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    2016 /*untilYear*/,
    5 /*untilMonth*/,
    1 /*untilDay*/,
    10 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },
  //             -4:00    -    -04
  {
    nullptr /*zonePolicy*/,
    "-04" /*format*/,
    -16 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Caracas[] ACE_TIME_PROGMEM = "America/Caracas";

const extended::ZoneInfo kZoneAmerica_Caracas ACE_TIME_PROGMEM = {
  kZoneNameAmerica_Caracas /*name*/,
  0x3be064f4 /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  3 /*numEras*/,
  kZoneEraAmerica_Caracas /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: America/Chicago
// Eras: 1
//---------------------------------------------------------------------------

static const extended::ZoneEra kZoneEraAmerica_Chicago[] ACE_TIME_PROGMEM = {
  //             -6:00    US    C%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "C%T" /*format*/,
    -24 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Chicago[] ACE_TIME_PROGMEM = "America/Chicago";

const extended::ZoneInfo kZoneAmerica_Chicago ACE_TIME_PROGMEM = {
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

static const extended::ZoneEra kZoneEraAmerica_Denver[] ACE_TIME_PROGMEM = {
  //             -7:00    US    M%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "M%T" /*format*/,
    -28 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Denver[] ACE_TIME_PROGMEM = "America/Denver";

const extended::ZoneInfo kZoneAmerica_Denver ACE_TIME_PROGMEM = {
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

static const extended::ZoneEra kZoneEraAmerica_Edmonton[] ACE_TIME_PROGMEM = {
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
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Edmonton[] ACE_TIME_PROGMEM = "America/Edmonton";

const extended::ZoneInfo kZoneAmerica_Edmonton ACE_TIME_PROGMEM = {
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

static const extended::ZoneEra kZoneEraAmerica_Los_Angeles[] ACE_TIME_PROGMEM = {
  //             -8:00    US    P%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "P%T" /*format*/,
    -32 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Los_Angeles[] ACE_TIME_PROGMEM = "America/Los_Angeles";

const extended::ZoneInfo kZoneAmerica_Los_Angeles ACE_TIME_PROGMEM = {
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

static const extended::ZoneEra kZoneEraAmerica_New_York[] ACE_TIME_PROGMEM = {
  //             -5:00    US    E%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "E%T" /*format*/,
    -20 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_New_York[] ACE_TIME_PROGMEM = "America/New_York";

const extended::ZoneInfo kZoneAmerica_New_York ACE_TIME_PROGMEM = {
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

static const extended::ZoneEra kZoneEraAmerica_Toronto[] ACE_TIME_PROGMEM = {
  //             -5:00    Canada    E%sT
  {
    &kZonePolicyCanada /*zonePolicy*/,
    "E%T" /*format*/,
    -20 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Toronto[] ACE_TIME_PROGMEM = "America/Toronto";

const extended::ZoneInfo kZoneAmerica_Toronto ACE_TIME_PROGMEM = {
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

static const extended::ZoneEra kZoneEraAmerica_Vancouver[] ACE_TIME_PROGMEM = {
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
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Vancouver[] ACE_TIME_PROGMEM = "America/Vancouver";

const extended::ZoneInfo kZoneAmerica_Vancouver ACE_TIME_PROGMEM = {
  kZoneNameAmerica_Vancouver /*name*/,
  0x2c6f6b1f /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  2 /*numEras*/,
  kZoneEraAmerica_Vancouver /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: America/Whitehorse
// Eras: 3
//---------------------------------------------------------------------------

static const extended::ZoneEra kZoneEraAmerica_Whitehorse[] ACE_TIME_PROGMEM = {
  //             -8:00    -    PST    1980
  {
    nullptr /*zonePolicy*/,
    "PST" /*format*/,
    -32 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    1980 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },
  //             -8:00    Canada    P%sT    2020 Nov  1
  {
    &kZonePolicyCanada /*zonePolicy*/,
    "P%T" /*format*/,
    -32 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    2020 /*untilYear*/,
    11 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },
  //             -7:00    -    MST
  {
    nullptr /*zonePolicy*/,
    "MST" /*format*/,
    -28 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Whitehorse[] ACE_TIME_PROGMEM = "America/Whitehorse";

const extended::ZoneInfo kZoneAmerica_Whitehorse ACE_TIME_PROGMEM = {
  kZoneNameAmerica_Whitehorse /*name*/,
  0x54e0e3e8 /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  3 /*numEras*/,
  kZoneEraAmerica_Whitehorse /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: America/Winnipeg
// Eras: 2
//---------------------------------------------------------------------------

static const extended::ZoneEra kZoneEraAmerica_Winnipeg[] ACE_TIME_PROGMEM = {
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
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAmerica_Winnipeg[] ACE_TIME_PROGMEM = "America/Winnipeg";

const extended::ZoneInfo kZoneAmerica_Winnipeg ACE_TIME_PROGMEM = {
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

static const extended::ZoneEra kZoneEraAustralia_Darwin[] ACE_TIME_PROGMEM = {
  //              9:30    Aus    AC%sT
  {
    &kZonePolicyAus /*zonePolicy*/,
    "AC%T" /*format*/,
    38 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameAustralia_Darwin[] ACE_TIME_PROGMEM = "Australia/Darwin";

const extended::ZoneInfo kZoneAustralia_Darwin ACE_TIME_PROGMEM = {
  kZoneNameAustralia_Darwin /*name*/,
  0x2876bdff /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  1 /*numEras*/,
  kZoneEraAustralia_Darwin /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: Europe/Lisbon
// Eras: 4
//---------------------------------------------------------------------------

static const extended::ZoneEra kZoneEraEurope_Lisbon[] ACE_TIME_PROGMEM = {
  //              0:00    Port    WE%sT    1983 Sep 25  1:00s
  {
    &kZonePolicyPort /*zonePolicy*/,
    "WE%T" /*format*/,
    0 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    1983 /*untilYear*/,
    9 /*untilMonth*/,
    25 /*untilDay*/,
    4 /*untilTimeCode*/,
    16 /*untilTimeModifier (kSuffixS + minute=0)*/,
  },
  //              0:00    W-Eur    WE%sT    1992 Sep 27  1:00s
  {
    &kZonePolicyW_Eur /*zonePolicy*/,
    "WE%T" /*format*/,
    0 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    1992 /*untilYear*/,
    9 /*untilMonth*/,
    27 /*untilDay*/,
    4 /*untilTimeCode*/,
    16 /*untilTimeModifier (kSuffixS + minute=0)*/,
  },
  //              1:00    EU    CE%sT    1996 Mar 31  1:00u
  {
    &kZonePolicyEU /*zonePolicy*/,
    "CE%T" /*format*/,
    4 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    1996 /*untilYear*/,
    3 /*untilMonth*/,
    31 /*untilDay*/,
    4 /*untilTimeCode*/,
    32 /*untilTimeModifier (kSuffixU + minute=0)*/,
  },
  //              0:00    EU    WE%sT
  {
    &kZonePolicyEU /*zonePolicy*/,
    "WE%T" /*format*/,
    0 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNameEurope_Lisbon[] ACE_TIME_PROGMEM = "Europe/Lisbon";

const extended::ZoneInfo kZoneEurope_Lisbon ACE_TIME_PROGMEM = {
  kZoneNameEurope_Lisbon /*name*/,
  0x5c00a70b /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  4 /*numEras*/,
  kZoneEraEurope_Lisbon /*eras*/,
  nullptr /*targetInfo*/,
};

//---------------------------------------------------------------------------
// Zone name: Pacific/Apia
// Eras: 2
//---------------------------------------------------------------------------

static const extended::ZoneEra kZoneEraPacific_Apia[] ACE_TIME_PROGMEM = {
  //             -11:00    WS    -11/-10    2011 Dec 29 24:00
  {
    &kZonePolicyWS /*zonePolicy*/,
    "-11/-10" /*format*/,
    -44 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    2011 /*untilYear*/,
    12 /*untilMonth*/,
    29 /*untilDay*/,
    96 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },
  //              13:00    WS    +13/+14
  {
    &kZonePolicyWS /*zonePolicy*/,
    "+13/+14" /*format*/,
    52 /*offsetCode*/,
    4 /*deltaCode (((offsetMinute=0) << 4) + ((deltaMinutes=0)/15 + 4))*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode*/,
    0 /*untilTimeModifier (kSuffixW + minute=0)*/,
  },

};

static const char kZoneNamePacific_Apia[] ACE_TIME_PROGMEM = "Pacific/Apia";

const extended::ZoneInfo kZonePacific_Apia ACE_TIME_PROGMEM = {
  kZoneNamePacific_Apia /*name*/,
  0x23359b5e /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  2 /*numEras*/,
  kZoneEraPacific_Apia /*eras*/,
  nullptr /*targetInfo*/,
};



//---------------------------------------------------------------------------
// Links: 1
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Link name: US/Pacific -> America/Los_Angeles
//---------------------------------------------------------------------------

static const char kZoneNameUS_Pacific[] ACE_TIME_PROGMEM = "US/Pacific";

const extended::ZoneInfo kZoneUS_Pacific ACE_TIME_PROGMEM = {
  kZoneNameUS_Pacific /*name*/,
  0xa950f6ab /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  1 /*numEras*/,
  kZoneEraAmerica_Los_Angeles /*eras*/,
  &kZoneAmerica_Los_Angeles /*targetInfo*/,
};


}
}
