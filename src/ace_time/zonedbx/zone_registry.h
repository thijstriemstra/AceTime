// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/dev/tz
//     --output_dir /home/brian/src/AceTime/src/ace_time/zonedbx
//     --tz_version 2022e
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
// from https://github.com/eggert/tz/releases/tag/2022e
//
// DO NOT EDIT

#ifndef ACE_TIME_ZONEDBX_ZONE_REGISTRY_H
#define ACE_TIME_ZONEDBX_ZONE_REGISTRY_H

#include <ace_time/internal/ZoneInfo.h>
#include <ace_time/internal/LinkEntry.h>

namespace ace_time {
namespace zonedbx {

// Zones
const uint16_t kZoneRegistrySize = 354;
extern const extended::ZoneInfo* const kZoneRegistry[354];

// Zones and Links
const uint16_t kZoneAndLinkRegistrySize = 595;
extern const extended::ZoneInfo* const kZoneAndLinkRegistry[595];

// Link Entries
const uint16_t kLinkRegistrySize = 241;
extern const extended::LinkEntry kLinkRegistry[241];

}
}
#endif
