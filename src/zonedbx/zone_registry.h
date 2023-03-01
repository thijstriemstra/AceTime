// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/zonedbx/tzfiles
//     --output_dir /home/brian/src/AceTime/src/zonedbx
//     --tz_version 2022g
//     --action zonedb
//     --language arduino
//     --scope extended
//     --generate_int16_years
//     --start_year 2000
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
// Supported Zones: 596 (351 zones, 245 links)
// Unsupported Zones: 0 (0 zones, 0 links)
// Original Years: [1844,2087]
// Generated Years: [1950,2087]
//
// Memory (8-bits):
//   Rules: 7205
//   Policies: 249
//   Eras: 7764
//   Zones: 4563
//   Links: 3185
//   Registry: 1192
//   Formats: 597
//   Letters: 46
//   Fragments: 150
//   Names: 5649 (original: 9076)
//   TOTAL: 30600
//
// Memory (32-bits):
//   Rules: 7860
//   Policies: 664
//   Eras: 10352
//   Zones: 8424
//   Links: 5880
//   Registry: 2384
//   Formats: 597
//   Letters: 64
//   Fragments: 178
//   Names: 5649 (original: 9076)
//   TOTAL: 42052
//
// DO NOT EDIT

#ifndef ACE_TIME_ZONEDBX_ZONE_REGISTRY_H
#define ACE_TIME_ZONEDBX_ZONE_REGISTRY_H

#include <zoneinfo/ZoneInfo.h>

namespace ace_time {
namespace zonedbx {

// Zones
const uint16_t kZoneRegistrySize = 351;
extern const extended::ZoneInfo* const kZoneRegistry[351];

// Zones and Links
const uint16_t kZoneAndLinkRegistrySize = 596;
extern const extended::ZoneInfo* const kZoneAndLinkRegistry[596];

}
}
#endif
