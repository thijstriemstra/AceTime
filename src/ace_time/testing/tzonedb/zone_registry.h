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
// Generated Years: [1943,2007]
//
// DO NOT EDIT

#ifndef ACE_TIME_TZONEDB_ZONE_REGISTRY_H
#define ACE_TIME_TZONEDB_ZONE_REGISTRY_H

#include <ace_time/internal/ZoneInfo.h>

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
