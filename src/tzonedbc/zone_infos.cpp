// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/tzonedbc/tzfiles
//     --output_dir /home/brian/src/AceTime/src/tzonedbc
//     --tz_version 2023c
//     --action zonedb
//     --language arduino
//     --scope complete
//     --db_namespace tzonedbc
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
// from https://github.com/eggert/tz/releases/tag/2023c
//
// Supported Zones: 16 (15 zones, 1 links)
// Unsupported Zones: 580 (335 zones, 245 links)
//
// Original Years:  [1844,2087]
// Generated Years: [1945,2087]
// Estimator Years: [1945,2090]
// Max Buffer Size: 7
//
// Records:
//   Rules: 227
//   Policies: 12
//   Eras: 30
//   Infos: 16
//
// Memory (8-bits):
//   Rules: 16
//   Rules: 2724
//   Policies: 36
//   Eras: 450
//   Zones: 195
//   Links: 13
//   Registry: 32
//   Formats: 92
//   Letters: 23
//   Fragments: 0
//   Names: 260 (original: 260)
//   TOTAL: 3841
//
// Memory (32-bits):
//   Rules: 24
//   Rules: 2724
//   Policies: 96
//   Eras: 600
//   Zones: 360
//   Links: 24
//   Registry: 64
//   Formats: 92
//   Letters: 33
//   Fragments: 0
//   Names: 260 (original: 260)
//   TOTAL: 4277
//
// DO NOT EDIT

#include <zoneinfo/compat.h>
#include "zone_policies.h"
#include "zone_infos.h"

namespace ace_time {
namespace tzonedbc {

//---------------------------------------------------------------------------
// ZoneContext (should not be in PROGMEM)
//---------------------------------------------------------------------------

const char kTzDatabaseVersion[] = "2023c";

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

const complete::ZoneContext kZoneContext = {
  1980 /*startYear*/,
  10000 /*untilYear*/,
  2100 /*baseYear*/,
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

static const complete::ZoneEra kZoneEraAfrica_Casablanca[] ACE_TIME_PROGMEM = {
  //              0:00    Morocco    +00/+01    1984 Mar 16
  {
    &kZonePolicyMorocco /*zonePolicy*/,
    "+00/+01" /*format*/,
    0 /*offsetCode (0/15)*/,
    0 /*offsetRemainder (0%15)*/,
    0 /*deltaMinutes*/,
    1984 /*untilYear*/,
    3 /*untilMonth*/,
    16 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },
  //              1:00    -    +01    1986
  {
    nullptr /*zonePolicy*/,
    "+01" /*format*/,
    240 /*offsetCode (3600/15)*/,
    0 /*offsetRemainder (3600%15)*/,
    0 /*deltaMinutes*/,
    1986 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },
  //              0:00    Morocco    +00/+01    2018 Oct 28  3:00
  {
    &kZonePolicyMorocco /*zonePolicy*/,
    "+00/+01" /*format*/,
    0 /*offsetCode (0/15)*/,
    0 /*offsetRemainder (0%15)*/,
    0 /*deltaMinutes*/,
    2018 /*untilYear*/,
    10 /*untilMonth*/,
    28 /*untilDay*/,
    720 /*untilTimeCode (10800/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },
  //              1:00    Morocco    +01/+00
  {
    &kZonePolicyMorocco /*zonePolicy*/,
    "+01/+00" /*format*/,
    240 /*offsetCode (3600/15)*/,
    0 /*offsetRemainder (3600%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNameAfrica_Casablanca[] ACE_TIME_PROGMEM = "Africa/Casablanca";

const complete::ZoneInfo kZoneAfrica_Casablanca ACE_TIME_PROGMEM = {
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

static const complete::ZoneEra kZoneEraAfrica_Windhoek[] ACE_TIME_PROGMEM = {
  //             2:00    -    SAST    1990 Mar 21
  {
    nullptr /*zonePolicy*/,
    "SAST" /*format*/,
    480 /*offsetCode (7200/15)*/,
    0 /*offsetRemainder (7200%15)*/,
    0 /*deltaMinutes*/,
    1990 /*untilYear*/,
    3 /*untilMonth*/,
    21 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },
  //             2:00    Namibia    %s
  {
    &kZonePolicyNamibia /*zonePolicy*/,
    "%" /*format*/,
    480 /*offsetCode (7200/15)*/,
    0 /*offsetRemainder (7200%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNameAfrica_Windhoek[] ACE_TIME_PROGMEM = "Africa/Windhoek";

const complete::ZoneInfo kZoneAfrica_Windhoek ACE_TIME_PROGMEM = {
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

static const complete::ZoneEra kZoneEraAmerica_Caracas[] ACE_TIME_PROGMEM = {
  //             -4:00    -    -04    2007 Dec  9  3:00
  {
    nullptr /*zonePolicy*/,
    "-04" /*format*/,
    -960 /*offsetCode (-14400/15)*/,
    0 /*offsetRemainder (-14400%15)*/,
    0 /*deltaMinutes*/,
    2007 /*untilYear*/,
    12 /*untilMonth*/,
    9 /*untilDay*/,
    720 /*untilTimeCode (10800/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },
  //             -4:30    -    -0430    2016 May  1  2:30
  {
    nullptr /*zonePolicy*/,
    "-0430" /*format*/,
    -1080 /*offsetCode (-16200/15)*/,
    0 /*offsetRemainder (-16200%15)*/,
    0 /*deltaMinutes*/,
    2016 /*untilYear*/,
    5 /*untilMonth*/,
    1 /*untilDay*/,
    600 /*untilTimeCode (9000/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },
  //             -4:00    -    -04
  {
    nullptr /*zonePolicy*/,
    "-04" /*format*/,
    -960 /*offsetCode (-14400/15)*/,
    0 /*offsetRemainder (-14400%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNameAmerica_Caracas[] ACE_TIME_PROGMEM = "America/Caracas";

const complete::ZoneInfo kZoneAmerica_Caracas ACE_TIME_PROGMEM = {
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

static const complete::ZoneEra kZoneEraAmerica_Chicago[] ACE_TIME_PROGMEM = {
  //             -6:00    US    C%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "C%T" /*format*/,
    -1440 /*offsetCode (-21600/15)*/,
    0 /*offsetRemainder (-21600%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNameAmerica_Chicago[] ACE_TIME_PROGMEM = "America/Chicago";

const complete::ZoneInfo kZoneAmerica_Chicago ACE_TIME_PROGMEM = {
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

static const complete::ZoneEra kZoneEraAmerica_Denver[] ACE_TIME_PROGMEM = {
  //             -7:00    US    M%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "M%T" /*format*/,
    -1680 /*offsetCode (-25200/15)*/,
    0 /*offsetRemainder (-25200%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNameAmerica_Denver[] ACE_TIME_PROGMEM = "America/Denver";

const complete::ZoneInfo kZoneAmerica_Denver ACE_TIME_PROGMEM = {
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

static const complete::ZoneEra kZoneEraAmerica_Edmonton[] ACE_TIME_PROGMEM = {
  //             -7:00    Edm    M%sT    1987
  {
    &kZonePolicyEdm /*zonePolicy*/,
    "M%T" /*format*/,
    -1680 /*offsetCode (-25200/15)*/,
    0 /*offsetRemainder (-25200%15)*/,
    0 /*deltaMinutes*/,
    1987 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },
  //             -7:00    Canada    M%sT
  {
    &kZonePolicyCanada /*zonePolicy*/,
    "M%T" /*format*/,
    -1680 /*offsetCode (-25200/15)*/,
    0 /*offsetRemainder (-25200%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNameAmerica_Edmonton[] ACE_TIME_PROGMEM = "America/Edmonton";

const complete::ZoneInfo kZoneAmerica_Edmonton ACE_TIME_PROGMEM = {
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

static const complete::ZoneEra kZoneEraAmerica_Los_Angeles[] ACE_TIME_PROGMEM = {
  //             -8:00    US    P%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "P%T" /*format*/,
    -1920 /*offsetCode (-28800/15)*/,
    0 /*offsetRemainder (-28800%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNameAmerica_Los_Angeles[] ACE_TIME_PROGMEM = "America/Los_Angeles";

const complete::ZoneInfo kZoneAmerica_Los_Angeles ACE_TIME_PROGMEM = {
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

static const complete::ZoneEra kZoneEraAmerica_New_York[] ACE_TIME_PROGMEM = {
  //             -5:00    US    E%sT
  {
    &kZonePolicyUS /*zonePolicy*/,
    "E%T" /*format*/,
    -1200 /*offsetCode (-18000/15)*/,
    0 /*offsetRemainder (-18000%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNameAmerica_New_York[] ACE_TIME_PROGMEM = "America/New_York";

const complete::ZoneInfo kZoneAmerica_New_York ACE_TIME_PROGMEM = {
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

static const complete::ZoneEra kZoneEraAmerica_Toronto[] ACE_TIME_PROGMEM = {
  //             -5:00    Canada    E%sT
  {
    &kZonePolicyCanada /*zonePolicy*/,
    "E%T" /*format*/,
    -1200 /*offsetCode (-18000/15)*/,
    0 /*offsetRemainder (-18000%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNameAmerica_Toronto[] ACE_TIME_PROGMEM = "America/Toronto";

const complete::ZoneInfo kZoneAmerica_Toronto ACE_TIME_PROGMEM = {
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

static const complete::ZoneEra kZoneEraAmerica_Vancouver[] ACE_TIME_PROGMEM = {
  //             -8:00    Vanc    P%sT    1987
  {
    &kZonePolicyVanc /*zonePolicy*/,
    "P%T" /*format*/,
    -1920 /*offsetCode (-28800/15)*/,
    0 /*offsetRemainder (-28800%15)*/,
    0 /*deltaMinutes*/,
    1987 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },
  //             -8:00    Canada    P%sT
  {
    &kZonePolicyCanada /*zonePolicy*/,
    "P%T" /*format*/,
    -1920 /*offsetCode (-28800/15)*/,
    0 /*offsetRemainder (-28800%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNameAmerica_Vancouver[] ACE_TIME_PROGMEM = "America/Vancouver";

const complete::ZoneInfo kZoneAmerica_Vancouver ACE_TIME_PROGMEM = {
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

static const complete::ZoneEra kZoneEraAmerica_Whitehorse[] ACE_TIME_PROGMEM = {
  //             -8:00    -    PST    1980
  {
    nullptr /*zonePolicy*/,
    "PST" /*format*/,
    -1920 /*offsetCode (-28800/15)*/,
    0 /*offsetRemainder (-28800%15)*/,
    0 /*deltaMinutes*/,
    1980 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },
  //             -8:00    Canada    P%sT    2020 Nov  1
  {
    &kZonePolicyCanada /*zonePolicy*/,
    "P%T" /*format*/,
    -1920 /*offsetCode (-28800/15)*/,
    0 /*offsetRemainder (-28800%15)*/,
    0 /*deltaMinutes*/,
    2020 /*untilYear*/,
    11 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },
  //             -7:00    -    MST
  {
    nullptr /*zonePolicy*/,
    "MST" /*format*/,
    -1680 /*offsetCode (-25200/15)*/,
    0 /*offsetRemainder (-25200%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNameAmerica_Whitehorse[] ACE_TIME_PROGMEM = "America/Whitehorse";

const complete::ZoneInfo kZoneAmerica_Whitehorse ACE_TIME_PROGMEM = {
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

static const complete::ZoneEra kZoneEraAmerica_Winnipeg[] ACE_TIME_PROGMEM = {
  //             -6:00    Winn    C%sT    2006
  {
    &kZonePolicyWinn /*zonePolicy*/,
    "C%T" /*format*/,
    -1440 /*offsetCode (-21600/15)*/,
    0 /*offsetRemainder (-21600%15)*/,
    0 /*deltaMinutes*/,
    2006 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },
  //             -6:00    Canada    C%sT
  {
    &kZonePolicyCanada /*zonePolicy*/,
    "C%T" /*format*/,
    -1440 /*offsetCode (-21600/15)*/,
    0 /*offsetRemainder (-21600%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNameAmerica_Winnipeg[] ACE_TIME_PROGMEM = "America/Winnipeg";

const complete::ZoneInfo kZoneAmerica_Winnipeg ACE_TIME_PROGMEM = {
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

static const complete::ZoneEra kZoneEraAustralia_Darwin[] ACE_TIME_PROGMEM = {
  //              9:30    Aus    AC%sT
  {
    &kZonePolicyAus /*zonePolicy*/,
    "AC%T" /*format*/,
    2280 /*offsetCode (34200/15)*/,
    0 /*offsetRemainder (34200%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNameAustralia_Darwin[] ACE_TIME_PROGMEM = "Australia/Darwin";

const complete::ZoneInfo kZoneAustralia_Darwin ACE_TIME_PROGMEM = {
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

static const complete::ZoneEra kZoneEraEurope_Lisbon[] ACE_TIME_PROGMEM = {
  //              0:00    Port    WE%sT    1983 Sep 25  1:00s
  {
    &kZonePolicyPort /*zonePolicy*/,
    "WE%T" /*format*/,
    0 /*offsetCode (0/15)*/,
    0 /*offsetRemainder (0%15)*/,
    0 /*deltaMinutes*/,
    1983 /*untilYear*/,
    9 /*untilMonth*/,
    25 /*untilDay*/,
    240 /*untilTimeCode (3600/15)*/,
    16 /*untilTimeModifier (kAtcSuffixS + seconds=0)*/,
  },
  //              0:00    W-Eur    WE%sT    1992 Sep 27  1:00s
  {
    &kZonePolicyW_Eur /*zonePolicy*/,
    "WE%T" /*format*/,
    0 /*offsetCode (0/15)*/,
    0 /*offsetRemainder (0%15)*/,
    0 /*deltaMinutes*/,
    1992 /*untilYear*/,
    9 /*untilMonth*/,
    27 /*untilDay*/,
    240 /*untilTimeCode (3600/15)*/,
    16 /*untilTimeModifier (kAtcSuffixS + seconds=0)*/,
  },
  //              1:00    EU    CE%sT    1996 Mar 31  1:00u
  {
    &kZonePolicyEU /*zonePolicy*/,
    "CE%T" /*format*/,
    240 /*offsetCode (3600/15)*/,
    0 /*offsetRemainder (3600%15)*/,
    0 /*deltaMinutes*/,
    1996 /*untilYear*/,
    3 /*untilMonth*/,
    31 /*untilDay*/,
    240 /*untilTimeCode (3600/15)*/,
    32 /*untilTimeModifier (kAtcSuffixU + seconds=0)*/,
  },
  //              0:00    EU    WE%sT
  {
    &kZonePolicyEU /*zonePolicy*/,
    "WE%T" /*format*/,
    0 /*offsetCode (0/15)*/,
    0 /*offsetRemainder (0%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNameEurope_Lisbon[] ACE_TIME_PROGMEM = "Europe/Lisbon";

const complete::ZoneInfo kZoneEurope_Lisbon ACE_TIME_PROGMEM = {
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

static const complete::ZoneEra kZoneEraPacific_Apia[] ACE_TIME_PROGMEM = {
  //             -11:00    WS    -11/-10    2011 Dec 29 24:00
  {
    &kZonePolicyWS /*zonePolicy*/,
    "-11/-10" /*format*/,
    -2640 /*offsetCode (-39600/15)*/,
    0 /*offsetRemainder (-39600%15)*/,
    0 /*deltaMinutes*/,
    2011 /*untilYear*/,
    12 /*untilMonth*/,
    29 /*untilDay*/,
    5760 /*untilTimeCode (86400/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },
  //              13:00    WS    +13/+14
  {
    &kZonePolicyWS /*zonePolicy*/,
    "+13/+14" /*format*/,
    3120 /*offsetCode (46800/15)*/,
    0 /*offsetRemainder (46800%15)*/,
    0 /*deltaMinutes*/,
    32767 /*untilYear*/,
    1 /*untilMonth*/,
    1 /*untilDay*/,
    0 /*untilTimeCode (0/15)*/,
    0 /*untilTimeModifier (kAtcSuffixW + seconds=0)*/,
  },

};

static const char kZoneNamePacific_Apia[] ACE_TIME_PROGMEM = "Pacific/Apia";

const complete::ZoneInfo kZonePacific_Apia ACE_TIME_PROGMEM = {
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

const complete::ZoneInfo kZoneUS_Pacific ACE_TIME_PROGMEM = {
  kZoneNameUS_Pacific /*name*/,
  0xa950f6ab /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  1 /*numEras*/,
  kZoneEraAmerica_Los_Angeles /*eras*/,
  &kZoneAmerica_Los_Angeles /*targetInfo*/,
};


}
}
