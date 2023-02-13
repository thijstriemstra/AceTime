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
// Generated Years: [1943,2087]
//
// DO NOT EDIT

#include <ace_time/common/compat.h>
#include "zone_infos.h"
#include "zone_registry.h"

namespace ace_time {
namespace tzonedbx {

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
