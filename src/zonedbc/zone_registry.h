// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/zonedbc/tzfiles
//     --output_dir /home/brian/src/AceTime/src/zonedbc
//     --tz_version 2023c
//     --action zonedb
//     --language arduino
//     --scope complete
//     --db_namespace zonedbc
//     --start_year 1800
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
// Supported Zones: 596 (350 zones, 246 links)
// Unsupported Zones: 0 (0 zones, 0 links)
//
// Original Years:  [1844,2087]
// Generated Years: [1844,2087]
// Estimator Years: [1800,2090]
// Max Buffer Size: 8
//
// Records:
//   Rules: 2238
//   Policies: 134
//   Eras: 1949
//   Infos: 596
//
// Memory (8-bits):
//   Rules: 16
//   Rules: 26856
//   Policies: 402
//   Eras: 29235
//   Zones: 4550
//   Links: 3198
//   Registry: 1192
//   Formats: 1032
//   Letters: 160
//   Fragments: 150
//   Names: 5649 (original: 9076)
//   TOTAL: 72440
//
// Memory (32-bits):
//   Rules: 24
//   Rules: 26856
//   Policies: 1072
//   Eras: 38980
//   Zones: 8400
//   Links: 5904
//   Registry: 2384
//   Formats: 1032
//   Letters: 216
//   Fragments: 178
//   Names: 5649 (original: 9076)
//   TOTAL: 90695
//
// DO NOT EDIT

#ifndef ACE_TIME_ZONEDBC_ZONE_REGISTRY_H
#define ACE_TIME_ZONEDBC_ZONE_REGISTRY_H

#include <zoneinfo/infos.h>

namespace ace_time {
namespace zonedbc {

// Zones
const uint16_t kZoneRegistrySize = 350;
extern const complete::ZoneInfo* const kZoneRegistry[350];

// Zones and Links
const uint16_t kZoneAndLinkRegistrySize = 596;
extern const complete::ZoneInfo* const kZoneAndLinkRegistry[596];

}
}
#endif
