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
// Original Years:  [1844,2087]
// Generated Years: [1945,2007]
// Estimator Years: [1945,2009]
// Max Buffer Size: 6
//
// Memory (8-bits):
//   Rules: 352
//   Policies: 24
//   Eras: 180
//   Zones: 143
//   Links: 13
//   Registry: 24
//   Formats: 38
//   Letters: 11
//   Fragments: 0
//   Names: 202 (original: 202)
//   TOTAL: 987
//
// Memory (32-bits):
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
//   TOTAL: 1281
//
// DO NOT EDIT

#include <zoneinfo/compat.h>
#include "zone_policies.h"

namespace ace_time {
namespace tzonedb {

//---------------------------------------------------------------------------
// Policies: 8
// Rules: 32
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Policy name: Aus
// Rules: 1
//---------------------------------------------------------------------------

static const basic::ZoneRule kZoneRulesAus[] ACE_TIME_PROGMEM = {
  // Anchor: Rule    Aus    1943    1944    -    Mar    lastSun    2:00s    0    S
  {
    -32767 /*fromYear*/,
    -32767 /*toYear*/,
    1 /*inMonth*/,
    0 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    0 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },

};

const basic::ZonePolicy kZonePolicyAus ACE_TIME_PROGMEM = {
  kZoneRulesAus /*rules*/,
  1 /*numRules*/,
};

//---------------------------------------------------------------------------
// Policy name: Canada
// Rules: 7
//---------------------------------------------------------------------------

static const basic::ZoneRule kZoneRulesCanada[] ACE_TIME_PROGMEM = {
  // Anchor: Rule    Canada    1945    only    -    Sep    30    2:00    0    S
  {
    -32767 /*fromYear*/,
    -32767 /*toYear*/,
    1 /*inMonth*/,
    0 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    0 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },
  // Rule    Canada    1945    only    -    Sep    30    2:00    0    S
  {
    1945 /*fromYear*/,
    1945 /*toYear*/,
    9 /*inMonth*/,
    0 /*onDayOfWeek*/,
    30 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },
  // Rule    Canada    1974    1986    -    Apr    lastSun    2:00    1:00    D
  {
    1974 /*fromYear*/,
    1986 /*toYear*/,
    4 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    8 /*deltaCode ((deltaMinutes=60)/15 + 4)*/,
    1 /*letterIndex ("D")*/,
  },
  // Rule    Canada    1974    2006    -    Oct    lastSun    2:00    0    S
  {
    1974 /*fromYear*/,
    2006 /*toYear*/,
    10 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },
  // Rule    Canada    1987    2006    -    Apr    Sun>=1    2:00    1:00    D
  {
    1987 /*fromYear*/,
    2006 /*toYear*/,
    4 /*inMonth*/,
    7 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    8 /*deltaCode ((deltaMinutes=60)/15 + 4)*/,
    1 /*letterIndex ("D")*/,
  },
  // Rule    Canada    2007    max    -    Mar    Sun>=8    2:00    1:00    D
  {
    2007 /*fromYear*/,
    32766 /*toYear*/,
    3 /*inMonth*/,
    7 /*onDayOfWeek*/,
    8 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    8 /*deltaCode ((deltaMinutes=60)/15 + 4)*/,
    1 /*letterIndex ("D")*/,
  },
  // Rule    Canada    2007    max    -    Nov    Sun>=1    2:00    0    S
  {
    2007 /*fromYear*/,
    32766 /*toYear*/,
    11 /*inMonth*/,
    7 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },

};

const basic::ZonePolicy kZonePolicyCanada ACE_TIME_PROGMEM = {
  kZoneRulesCanada /*rules*/,
  7 /*numRules*/,
};

//---------------------------------------------------------------------------
// Policy name: Ecuador
// Rules: 3
//---------------------------------------------------------------------------

static const basic::ZoneRule kZoneRulesEcuador[] ACE_TIME_PROGMEM = {
  // Anchor: Rule    Ecuador    1993    only    -    Feb     5    0:00    0    -
  {
    -32767 /*fromYear*/,
    -32767 /*toYear*/,
    1 /*inMonth*/,
    0 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    0 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    0 /*letterIndex ("")*/,
  },
  // Rule    Ecuador    1992    only    -    Nov    28    0:00    1:00    -
  {
    1992 /*fromYear*/,
    1992 /*toYear*/,
    11 /*inMonth*/,
    0 /*onDayOfWeek*/,
    28 /*onDayOfMonth*/,
    0 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    8 /*deltaCode ((deltaMinutes=60)/15 + 4)*/,
    0 /*letterIndex ("")*/,
  },
  // Rule    Ecuador    1993    only    -    Feb     5    0:00    0    -
  {
    1993 /*fromYear*/,
    1993 /*toYear*/,
    2 /*inMonth*/,
    0 /*onDayOfWeek*/,
    5 /*onDayOfMonth*/,
    0 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    0 /*letterIndex ("")*/,
  },

};

const basic::ZonePolicy kZonePolicyEcuador ACE_TIME_PROGMEM = {
  kZoneRulesEcuador /*rules*/,
  3 /*numRules*/,
};

//---------------------------------------------------------------------------
// Policy name: Edm
// Rules: 4
//---------------------------------------------------------------------------

static const basic::ZoneRule kZoneRulesEdm[] ACE_TIME_PROGMEM = {
  // Anchor: Rule    Edm    1947    only    -    Sep    lastSun    2:00    0    S
  {
    -32767 /*fromYear*/,
    -32767 /*toYear*/,
    1 /*inMonth*/,
    0 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    0 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },
  // Rule    Edm    1947    only    -    Sep    lastSun    2:00    0    S
  {
    1947 /*fromYear*/,
    1947 /*toYear*/,
    9 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },
  // Rule    Edm    1972    1986    -    Apr    lastSun    2:00    1:00    D
  {
    1972 /*fromYear*/,
    1986 /*toYear*/,
    4 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    8 /*deltaCode ((deltaMinutes=60)/15 + 4)*/,
    1 /*letterIndex ("D")*/,
  },
  // Rule    Edm    1972    2006    -    Oct    lastSun    2:00    0    S
  {
    1972 /*fromYear*/,
    2006 /*toYear*/,
    10 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },

};

const basic::ZonePolicy kZonePolicyEdm ACE_TIME_PROGMEM = {
  kZoneRulesEdm /*rules*/,
  4 /*numRules*/,
};

//---------------------------------------------------------------------------
// Policy name: SA
// Rules: 1
//---------------------------------------------------------------------------

static const basic::ZoneRule kZoneRulesSA[] ACE_TIME_PROGMEM = {
  // Anchor: Rule    SA    1943    1944    -    Mar    Sun>=15    2:00    0    -
  {
    -32767 /*fromYear*/,
    -32767 /*toYear*/,
    1 /*inMonth*/,
    0 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    0 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    0 /*letterIndex ("")*/,
  },

};

const basic::ZonePolicy kZonePolicySA ACE_TIME_PROGMEM = {
  kZoneRulesSA /*rules*/,
  1 /*numRules*/,
};

//---------------------------------------------------------------------------
// Policy name: US
// Rules: 7
//---------------------------------------------------------------------------

static const basic::ZoneRule kZoneRulesUS[] ACE_TIME_PROGMEM = {
  // Anchor: Rule    US    1967    2006    -    Oct    lastSun    2:00    0    S
  {
    -32767 /*fromYear*/,
    -32767 /*toYear*/,
    1 /*inMonth*/,
    0 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    0 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },
  // Rule    US    1967    2006    -    Oct    lastSun    2:00    0    S
  {
    1967 /*fromYear*/,
    2006 /*toYear*/,
    10 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },
  // Rule    US    1975    only    -    Feb    lastSun    2:00    1:00    D
  {
    1975 /*fromYear*/,
    1975 /*toYear*/,
    2 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    8 /*deltaCode ((deltaMinutes=60)/15 + 4)*/,
    1 /*letterIndex ("D")*/,
  },
  // Rule    US    1976    1986    -    Apr    lastSun    2:00    1:00    D
  {
    1976 /*fromYear*/,
    1986 /*toYear*/,
    4 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    8 /*deltaCode ((deltaMinutes=60)/15 + 4)*/,
    1 /*letterIndex ("D")*/,
  },
  // Rule    US    1987    2006    -    Apr    Sun>=1    2:00    1:00    D
  {
    1987 /*fromYear*/,
    2006 /*toYear*/,
    4 /*inMonth*/,
    7 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    8 /*deltaCode ((deltaMinutes=60)/15 + 4)*/,
    1 /*letterIndex ("D")*/,
  },
  // Rule    US    2007    max    -    Mar    Sun>=8    2:00    1:00    D
  {
    2007 /*fromYear*/,
    32766 /*toYear*/,
    3 /*inMonth*/,
    7 /*onDayOfWeek*/,
    8 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    8 /*deltaCode ((deltaMinutes=60)/15 + 4)*/,
    1 /*letterIndex ("D")*/,
  },
  // Rule    US    2007    max    -    Nov    Sun>=1    2:00    0    S
  {
    2007 /*fromYear*/,
    32766 /*toYear*/,
    11 /*inMonth*/,
    7 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },

};

const basic::ZonePolicy kZonePolicyUS ACE_TIME_PROGMEM = {
  kZoneRulesUS /*rules*/,
  7 /*numRules*/,
};

//---------------------------------------------------------------------------
// Policy name: Vanc
// Rules: 4
//---------------------------------------------------------------------------

static const basic::ZoneRule kZoneRulesVanc[] ACE_TIME_PROGMEM = {
  // Anchor: Rule    Vanc    1947    1961    -    Sep    lastSun    2:00    0    S
  {
    -32767 /*fromYear*/,
    -32767 /*toYear*/,
    1 /*inMonth*/,
    0 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    0 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },
  // Rule    Vanc    1946    1986    -    Apr    lastSun    2:00    1:00    D
  {
    1946 /*fromYear*/,
    1986 /*toYear*/,
    4 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    8 /*deltaCode ((deltaMinutes=60)/15 + 4)*/,
    1 /*letterIndex ("D")*/,
  },
  // Rule    Vanc    1947    1961    -    Sep    lastSun    2:00    0    S
  {
    1947 /*fromYear*/,
    1961 /*toYear*/,
    9 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },
  // Rule    Vanc    1962    2006    -    Oct    lastSun    2:00    0    S
  {
    1962 /*fromYear*/,
    2006 /*toYear*/,
    10 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },

};

const basic::ZonePolicy kZonePolicyVanc ACE_TIME_PROGMEM = {
  kZoneRulesVanc /*rules*/,
  4 /*numRules*/,
};

//---------------------------------------------------------------------------
// Policy name: Winn
// Rules: 5
//---------------------------------------------------------------------------

static const basic::ZoneRule kZoneRulesWinn[] ACE_TIME_PROGMEM = {
  // Anchor: Rule    Winn    1963    only    -    Sep    22    2:00    0    S
  {
    -32767 /*fromYear*/,
    -32767 /*toYear*/,
    1 /*inMonth*/,
    0 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    0 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },
  // Rule    Winn    1963    only    -    Sep    22    2:00    0    S
  {
    1963 /*fromYear*/,
    1963 /*toYear*/,
    9 /*inMonth*/,
    0 /*onDayOfWeek*/,
    22 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },
  // Rule    Winn    1966    1986    -    Apr    lastSun    2:00s    1:00    D
  {
    1966 /*fromYear*/,
    1986 /*toYear*/,
    4 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    16 /*atTimeModifier (kSuffixS + minute=0)*/,
    8 /*deltaCode ((deltaMinutes=60)/15 + 4)*/,
    1 /*letterIndex ("D")*/,
  },
  // Rule    Winn    1966    2005    -    Oct    lastSun    2:00s    0    S
  {
    1966 /*fromYear*/,
    2005 /*toYear*/,
    10 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    16 /*atTimeModifier (kSuffixS + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=0)/15 + 4)*/,
    2 /*letterIndex ("S")*/,
  },
  // Rule    Winn    1987    2005    -    Apr    Sun>=1    2:00s    1:00    D
  {
    1987 /*fromYear*/,
    2005 /*toYear*/,
    4 /*inMonth*/,
    7 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    16 /*atTimeModifier (kSuffixS + minute=0)*/,
    8 /*deltaCode ((deltaMinutes=60)/15 + 4)*/,
    1 /*letterIndex ("D")*/,
  },

};

const basic::ZonePolicy kZonePolicyWinn ACE_TIME_PROGMEM = {
  kZoneRulesWinn /*rules*/,
  5 /*numRules*/,
};



}
}
