// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/dev/tz
//     --output_dir /home/brian/src/AceTime/src/ace_time/zonedbx
//     --tz_version 2021d
//     --action zonedb
//     --language arduino
//     --scope extended
//     --start_year 2000
//     --until_year 2050
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
// from https://github.com/eggert/tz/releases/tag/2021d
//
// DO NOT EDIT

#ifndef ACE_TIME_ZONEDBX_ZONE_REGISTRY_H
#define ACE_TIME_ZONEDBX_ZONE_REGISTRY_H

#include <ace_time/internal/ZoneInfo.h>
#include <ace_time/internal/LinkEntry.h>

namespace ace_time {
namespace zonedbx {

// Zones
const uint16_t kZoneRegistrySize = 377;
extern const extended::ZoneInfo* const kZoneRegistry[377];

// Zones and Links
const uint16_t kZoneAndLinkRegistrySize = 594;
extern const extended::ZoneInfo* const kZoneAndLinkRegistry[594];

// Link Entries
const uint16_t kLinkRegistrySize = 217;
extern const extended::LinkEntry kLinkRegistry[217];

}
}
#endif
