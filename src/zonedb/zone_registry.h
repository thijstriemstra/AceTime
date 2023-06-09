// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/zonedb/tzfiles
//     --output_dir /home/brian/src/AceTime/src/zonedb
//     --tz_version 2023c
//     --action zonedb
//     --language arduino
//     --scope basic
//     --db_namespace zonedb
//     --start_year 2000
//     --until_year 2200
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
// Supported Zones: 446 (226 zones, 220 links)
// Unsupported Zones: 150 (124 zones, 26 links)
//
// Original Years:  [1844,2087]
// Generated Years: [1950,2023]
// Estimator Years: [1950,2025]
// Max Buffer Size: 6
//
// Records:
//   Infos: 446
//   Eras: 238
//   Policies: 63
//   Rules: 362
//
// Memory (8-bits):
//   Context: 16
//   Rules: 3258
//   Policies: 189
//   Eras: 2618
//   Zones: 2938
//   Links: 2860
//   Registry: 892
//   Formats: 465
//   Letters: 11
//   Fragments: 116
//   Names: 4144 (original: 6503)
//   TOTAL: 17507
//
// Memory (32-bits):
//   Context: 24
//   Rules: 4344
//   Policies: 504
//   Eras: 3808
//   Zones: 5424
//   Links: 5280
//   Registry: 1784
//   Formats: 465
//   Letters: 17
//   Fragments: 138
//   Names: 4144 (original: 6503)
//   TOTAL: 25932
//
// DO NOT EDIT

#ifndef ACE_TIME_ZONEDB_ZONE_REGISTRY_H
#define ACE_TIME_ZONEDB_ZONE_REGISTRY_H

#include <zoneinfo/infos.h>

namespace ace_time {
namespace zonedb {

// Zones
const uint16_t kZoneRegistrySize = 226;
extern const basic::ZoneInfo* const kZoneRegistry[226];

// Zones and Links
const uint16_t kZoneAndLinkRegistrySize = 446;
extern const basic::ZoneInfo* const kZoneAndLinkRegistry[446];

}
}
#endif
