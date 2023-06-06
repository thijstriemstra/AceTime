// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/tzonedb/tzfiles
//     --output_dir /home/brian/src/AceTime/src/tzonedb
//     --tz_version 2023c
//     --action zonedb
//     --language arduino
//     --scope basic
//     --db_namespace tzonedb
//     --include_list include_list.txt
//     --nocompress
//     --start_year 1980
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
// Supported Zones: 12 (11 zones, 1 links)
// Unsupported Zones: 584 (339 zones, 245 links)
//
// Original Years:  [1844,2087]
// Generated Years: [1945,2007]
// Estimator Years: [1945,2009]
// Max Buffer Size: 6
//
// Records:
//   Infos: 12
//   Eras: 15
//   Policies: 8
//   Rules: 32
//
// Memory (8-bits):
//   Rules: 288
//   Policies: 24
//   Eras: 165
//   Zones: 143
//   Links: 13
//   Registry: 24
//   Formats: 38
//   Letters: 11
//   Fragments: 0
//   Names: 202 (original: 202)
//   TOTAL: 908
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

#ifndef ACE_TIME_TZONEDB_ZONE_REGISTRY_H
#define ACE_TIME_TZONEDB_ZONE_REGISTRY_H

#include <zoneinfo/infos.h>

namespace ace_time {
namespace tzonedb {

// Zones
const uint16_t kZoneRegistrySize = 11;
extern const basic::ZoneInfo* const kZoneRegistry[11];

// Zones and Links
const uint16_t kZoneAndLinkRegistrySize = 12;
extern const basic::ZoneInfo* const kZoneAndLinkRegistry[12];

}
}
#endif
