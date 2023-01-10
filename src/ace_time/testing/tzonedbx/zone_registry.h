// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/ace_time/testing/tzonedbx/tzfiles
//     --output_dir /home/brian/src/AceTime/src/ace_time/testing/tzonedbx
//     --tz_version 2022g
//     --action zonedb
//     --language arduino
//     --scope extended
//     --db_namespace tzonedbx
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
// DO NOT EDIT

#ifndef ACE_TIME_TZONEDBX_ZONE_REGISTRY_H
#define ACE_TIME_TZONEDBX_ZONE_REGISTRY_H

#include <ace_time/internal/ZoneInfo.h>
#include <ace_time/internal/LinkEntry.h>

namespace ace_time {
namespace tzonedbx {

// Zones
const uint16_t kZoneRegistrySize = 2;
extern const extended::ZoneInfo* const kZoneRegistry[2];

// Zones and Links
const uint16_t kZoneAndLinkRegistrySize = 3;
extern const extended::ZoneInfo* const kZoneAndLinkRegistry[3];

// Link Entries
const uint16_t kLinkRegistrySize = 1;
extern const extended::LinkEntry kLinkRegistry[1];

}
}
#endif
