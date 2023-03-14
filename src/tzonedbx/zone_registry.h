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
//
// Original Years:  [1844,2087]
// Generated Years: [1945,2087]
// Estimator Years: [1945,2090]
// Max Buffer Size: 7
//
// Records:
//   Infos: 16
//   Eras: 30
//   Policies: 12
//   Rules: 227
//
// Memory (8-bits):
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
//   TOTAL: 3508
//
// Memory (32-bits):
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
//   TOTAL: 4133
//
// DO NOT EDIT

#ifndef ACE_TIME_TZONEDBX_ZONE_REGISTRY_H
#define ACE_TIME_TZONEDBX_ZONE_REGISTRY_H

#include <zoneinfo/ZoneInfo.h>

namespace ace_time {
namespace tzonedbx {

// Zones
const uint16_t kZoneRegistrySize = 15;
extern const extended::ZoneInfo* const kZoneRegistry[15];

// Zones and Links
const uint16_t kZoneAndLinkRegistrySize = 16;
extern const extended::ZoneInfo* const kZoneAndLinkRegistry[16];

}
}
#endif
