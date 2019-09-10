// This file was generated by the following script:
//
//   $ ../../../tools/tzcompiler.py --input_dir ../../../tools/../../tz --output_dir /home/brian/dev/AceTime/src/ace_time/zonedb --tz_version 2019b --action zonedb --language arduino --scope basic --start_year 2000 --until_year 2050
//
// using the TZ Database files from
// https://github.com/eggert/tz/releases/tag/2019b
//
// DO NOT EDIT

#ifndef ACE_TIME_ZONEDB_ZONE_REGISTRY_H
#define ACE_TIME_ZONEDB_ZONE_REGISTRY_H

#include <ace_time/internal/ZoneInfo.h>

namespace ace_time {
namespace zonedb {

const uint16_t kZoneRegistrySize = 270;

extern const basic::ZoneInfo* const kZoneRegistry[270];

}
}
#endif