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
// Generated Years: [1945,2007]
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
#include "zone_infos.h"
#include "zone_registry.h"

namespace ace_time {
namespace tzonedb {

//---------------------------------------------------------------------------
// Zone Info registry. Sorted by zoneId.
//---------------------------------------------------------------------------
const basic::ZoneInfo* const kZoneRegistry[11] ACE_TIME_PROGMEM = {
  &kZoneAmerica_New_York, // 0x1e2a7654, America/New_York
  &kZoneAustralia_Darwin, // 0x2876bdff, Australia/Darwin
  &kZoneAmerica_Vancouver, // 0x2c6f6b1f, America/Vancouver
  &kZoneAmerica_Chicago, // 0x4b92b5d4, America/Chicago
  &kZoneAmerica_Edmonton, // 0x6cb9484a, America/Edmonton
  &kZoneAmerica_Toronto, // 0x792e851b, America/Toronto
  &kZoneAmerica_Winnipeg, // 0x8c7dafc7, America/Winnipeg
  &kZoneAmerica_Denver, // 0x97d10b2a, America/Denver
  &kZonePacific_Galapagos, // 0xa952f752, Pacific/Galapagos
  &kZoneAmerica_Los_Angeles, // 0xb7f7e8f2, America/Los_Angeles
  &kZoneAfrica_Johannesburg, // 0xd5d157a0, Africa/Johannesburg

};

//---------------------------------------------------------------------------
// Zone and Link (fat) Info registry. Sorted by zoneId. Links act like Zones.
//---------------------------------------------------------------------------
const basic::ZoneInfo* const kZoneAndLinkRegistry[12] ACE_TIME_PROGMEM = {
  &kZoneAmerica_New_York, // 0x1e2a7654, America/New_York
  &kZoneAustralia_Darwin, // 0x2876bdff, Australia/Darwin
  &kZoneAmerica_Vancouver, // 0x2c6f6b1f, America/Vancouver
  &kZoneAmerica_Chicago, // 0x4b92b5d4, America/Chicago
  &kZoneAmerica_Edmonton, // 0x6cb9484a, America/Edmonton
  &kZoneAmerica_Toronto, // 0x792e851b, America/Toronto
  &kZoneAmerica_Winnipeg, // 0x8c7dafc7, America/Winnipeg
  &kZoneAmerica_Denver, // 0x97d10b2a, America/Denver
  &kZoneUS_Pacific, // 0xa950f6ab, US/Pacific -> America/Los_Angeles
  &kZonePacific_Galapagos, // 0xa952f752, Pacific/Galapagos
  &kZoneAmerica_Los_Angeles, // 0xb7f7e8f2, America/Los_Angeles
  &kZoneAfrica_Johannesburg, // 0xd5d157a0, Africa/Johannesburg

};

}
}
