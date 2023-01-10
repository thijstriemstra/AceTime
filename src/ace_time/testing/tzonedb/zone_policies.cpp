// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/ace_time/testing/tzonedb/tzfiles
//     --output_dir /home/brian/src/AceTime/src/ace_time/testing/tzonedb
//     --tz_version 2022g
//     --action zonedb
//     --language arduino
//     --scope basic
//     --db_namespace tzonedb
//     --generate_int16_years
//     --include_list include_list.txt
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
// Policies: 4
// Rules: 11
// Letter Size (bytes): 0
// Total Memory 8-bit (bytes): 123
// Total Memory 32-bit (bytes): 180
//
// DO NOT EDIT

#include <ace_time/common/compat.h>
#include "zone_policies.h"

namespace ace_time {
namespace tzonedb {

//---------------------------------------------------------------------------
// Policy name: Aus
// Rules: 1
// Memory (8-bit): 15
// Memory (32-bit): 24
//---------------------------------------------------------------------------

static const basic::ZoneRule kZoneRulesAus[] ACE_TIME_PROGMEM = {
  // Rule    Aus    1943    1944    -    Mar    lastSun    2:00s    0    S
  {
    1943 /*fromYear*/,
    1944 /*toYear*/,
    3 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    16 /*atTimeModifier (kSuffixS + minute=0)*/,
    0 /*deltaCode ((deltaMinutes=0)/15)*/,
    'S' /*letter*/,
  },

};



const basic::ZonePolicy kZonePolicyAus ACE_TIME_PROGMEM = {
  kZoneRulesAus /*rules*/,
  nullptr /*letters*/,
  1 /*numRules*/,
  0 /*numLetters*/,
};

//---------------------------------------------------------------------------
// Policy name: Ecuador
// Rules: 3
// Memory (8-bit): 33
// Memory (32-bit): 48
//---------------------------------------------------------------------------

static const basic::ZoneRule kZoneRulesEcuador[] ACE_TIME_PROGMEM = {
  // Anchor: Rule    Ecuador    1993    only    -    Feb     5    0:00    0    -
  {
    0 /*fromYear*/,
    0 /*toYear*/,
    1 /*inMonth*/,
    0 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    0 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    0 /*deltaCode ((deltaMinutes=0)/15)*/,
    '-' /*letter*/,
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
    4 /*deltaCode ((deltaMinutes=60)/15)*/,
    '-' /*letter*/,
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
    0 /*deltaCode ((deltaMinutes=0)/15)*/,
    '-' /*letter*/,
  },

};



const basic::ZonePolicy kZonePolicyEcuador ACE_TIME_PROGMEM = {
  kZoneRulesEcuador /*rules*/,
  nullptr /*letters*/,
  3 /*numRules*/,
  0 /*numLetters*/,
};

//---------------------------------------------------------------------------
// Policy name: SA
// Rules: 1
// Memory (8-bit): 15
// Memory (32-bit): 24
//---------------------------------------------------------------------------

static const basic::ZoneRule kZoneRulesSA[] ACE_TIME_PROGMEM = {
  // Rule    SA    1943    1944    -    Mar    Sun>=15    2:00    0    -
  {
    1943 /*fromYear*/,
    1944 /*toYear*/,
    3 /*inMonth*/,
    7 /*onDayOfWeek*/,
    15 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    0 /*deltaCode ((deltaMinutes=0)/15)*/,
    '-' /*letter*/,
  },

};



const basic::ZonePolicy kZonePolicySA ACE_TIME_PROGMEM = {
  kZoneRulesSA /*rules*/,
  nullptr /*letters*/,
  1 /*numRules*/,
  0 /*numLetters*/,
};

//---------------------------------------------------------------------------
// Policy name: US
// Rules: 6
// Memory (8-bit): 60
// Memory (32-bit): 84
//---------------------------------------------------------------------------

static const basic::ZoneRule kZoneRulesUS[] ACE_TIME_PROGMEM = {
  // Rule    US    1967    2006    -    Oct    lastSun    2:00    0    S
  {
    1967 /*fromYear*/,
    2006 /*toYear*/,
    10 /*inMonth*/,
    7 /*onDayOfWeek*/,
    0 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    0 /*deltaCode ((deltaMinutes=0)/15)*/,
    'S' /*letter*/,
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
    4 /*deltaCode ((deltaMinutes=60)/15)*/,
    'D' /*letter*/,
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
    4 /*deltaCode ((deltaMinutes=60)/15)*/,
    'D' /*letter*/,
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
    4 /*deltaCode ((deltaMinutes=60)/15)*/,
    'D' /*letter*/,
  },
  // Rule    US    2007    max    -    Mar    Sun>=8    2:00    1:00    D
  {
    2007 /*fromYear*/,
    9999 /*toYear*/,
    3 /*inMonth*/,
    7 /*onDayOfWeek*/,
    8 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    4 /*deltaCode ((deltaMinutes=60)/15)*/,
    'D' /*letter*/,
  },
  // Rule    US    2007    max    -    Nov    Sun>=1    2:00    0    S
  {
    2007 /*fromYear*/,
    9999 /*toYear*/,
    11 /*inMonth*/,
    7 /*onDayOfWeek*/,
    1 /*onDayOfMonth*/,
    8 /*atTimeCode*/,
    0 /*atTimeModifier (kSuffixW + minute=0)*/,
    0 /*deltaCode ((deltaMinutes=0)/15)*/,
    'S' /*letter*/,
  },

};



const basic::ZonePolicy kZonePolicyUS ACE_TIME_PROGMEM = {
  kZoneRulesUS /*rules*/,
  nullptr /*letters*/,
  6 /*numRules*/,
  0 /*numLetters*/,
};



}
}
