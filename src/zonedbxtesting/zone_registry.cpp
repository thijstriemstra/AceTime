// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/zonedbxtesting/tzfiles
//     --output_dir /home/brian/src/AceTime/src/zonedbxtesting
//     --tz_version 2023c
//     --action zonedb
//     --language arduino
//     --scope extended
//     --db_namespace zonedbxtesting
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
//   Context: 16
//   Rules: 2497
//   Policies: 36
//   Eras: 360
//   Zones: 195
//   Links: 13
//   Registry: 32
//   Formats: 92
//   Letters: 23
//   Fragments: 0
//   Names: 260 (original: 260)
//   TOTAL: 3524
//
// Memory (32-bits):
//   Context: 24
//   Rules: 2724
//   Policies: 96
//   Eras: 480
//   Zones: 360
//   Links: 24
//   Registry: 64
//   Formats: 92
//   Letters: 33
//   Fragments: 0
//   Names: 260 (original: 260)
//   TOTAL: 4157
//
// DO NOT EDIT

#include <zoneinfo/compat.h>
#include "zone_infos.h"
#include "zone_registry.h"

namespace ace_time {
namespace zonedbxtesting {

//---------------------------------------------------------------------------
// Zone Info registry. Sorted by zoneId.
//---------------------------------------------------------------------------
const extended::ZoneInfo* const kZoneRegistry[15] ACE_TIME_PROGMEM = {
  &kZoneAmerica_New_York, // 0x1e2a7654, America/New_York
  &kZonePacific_Apia, // 0x23359b5e, Pacific/Apia
  &kZoneAustralia_Darwin, // 0x2876bdff, Australia/Darwin
  &kZoneAmerica_Vancouver, // 0x2c6f6b1f, America/Vancouver
  &kZoneAmerica_Caracas, // 0x3be064f4, America/Caracas
  &kZoneAmerica_Chicago, // 0x4b92b5d4, America/Chicago
  &kZoneAmerica_Whitehorse, // 0x54e0e3e8, America/Whitehorse
  &kZoneEurope_Lisbon, // 0x5c00a70b, Europe/Lisbon
  &kZoneAmerica_Edmonton, // 0x6cb9484a, America/Edmonton
  &kZoneAfrica_Windhoek, // 0x789c9bd3, Africa/Windhoek
  &kZoneAmerica_Toronto, // 0x792e851b, America/Toronto
  &kZoneAmerica_Winnipeg, // 0x8c7dafc7, America/Winnipeg
  &kZoneAmerica_Denver, // 0x97d10b2a, America/Denver
  &kZoneAmerica_Los_Angeles, // 0xb7f7e8f2, America/Los_Angeles
  &kZoneAfrica_Casablanca, // 0xc59f1b33, Africa/Casablanca

};

//---------------------------------------------------------------------------
// Zone and Link (fat) Info registry. Sorted by zoneId. Links act like Zones.
//---------------------------------------------------------------------------
const extended::ZoneInfo* const kZoneAndLinkRegistry[16] ACE_TIME_PROGMEM = {
  &kZoneAmerica_New_York, // 0x1e2a7654, America/New_York
  &kZonePacific_Apia, // 0x23359b5e, Pacific/Apia
  &kZoneAustralia_Darwin, // 0x2876bdff, Australia/Darwin
  &kZoneAmerica_Vancouver, // 0x2c6f6b1f, America/Vancouver
  &kZoneAmerica_Caracas, // 0x3be064f4, America/Caracas
  &kZoneAmerica_Chicago, // 0x4b92b5d4, America/Chicago
  &kZoneAmerica_Whitehorse, // 0x54e0e3e8, America/Whitehorse
  &kZoneEurope_Lisbon, // 0x5c00a70b, Europe/Lisbon
  &kZoneAmerica_Edmonton, // 0x6cb9484a, America/Edmonton
  &kZoneAfrica_Windhoek, // 0x789c9bd3, Africa/Windhoek
  &kZoneAmerica_Toronto, // 0x792e851b, America/Toronto
  &kZoneAmerica_Winnipeg, // 0x8c7dafc7, America/Winnipeg
  &kZoneAmerica_Denver, // 0x97d10b2a, America/Denver
  &kZoneUS_Pacific, // 0xa950f6ab, US/Pacific -> America/Los_Angeles
  &kZoneAmerica_Los_Angeles, // 0xb7f7e8f2, America/Los_Angeles
  &kZoneAfrica_Casablanca, // 0xc59f1b33, Africa/Casablanca

};

}
}
