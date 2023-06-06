// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/tzonedbx/tzfiles
//     --output_dir /home/brian/src/AceTime/src/tzonedbx
//     --tz_version 2023c
//     --action zonedb
//     --language arduino
//     --scope extended
//     --db_namespace tzonedbx
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
// from https://github.com/eggert/tz/releases/tag/2023c
//
// Supported Zones: 16 (15 zones, 1 links)
// Unsupported Zones: 580 (335 zones, 245 links)
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

#ifndef ACE_TIME_TZONEDBX_ZONE_POLICIES_H
#define ACE_TIME_TZONEDBX_ZONE_POLICIES_H

#include <zoneinfo/ZoneInfo.h>

namespace ace_time {
namespace tzonedbx {

//---------------------------------------------------------------------------
// Supported policies: 12
// Supported rules: 227
//---------------------------------------------------------------------------

extern const extended::ZonePolicy kZonePolicyAus;
extern const extended::ZonePolicy kZonePolicyCanada;
extern const extended::ZonePolicy kZonePolicyEU;
extern const extended::ZonePolicy kZonePolicyEdm;
extern const extended::ZonePolicy kZonePolicyMorocco;
extern const extended::ZonePolicy kZonePolicyNamibia;
extern const extended::ZonePolicy kZonePolicyPort;
extern const extended::ZonePolicy kZonePolicyUS;
extern const extended::ZonePolicy kZonePolicyVanc;
extern const extended::ZonePolicy kZonePolicyW_Eur;
extern const extended::ZonePolicy kZonePolicyWS;
extern const extended::ZonePolicy kZonePolicyWinn;


//---------------------------------------------------------------------------
// Unsupported policies: 122
//---------------------------------------------------------------------------

// AN {unused}
// AQ {unused}
// AS {unused}
// AT {unused}
// AV {unused}
// AW {unused}
// Albania {unused}
// Algeria {unused}
// Arg {unused}
// Armenia {unused}
// Austria {unused}
// Azer {unused}
// Barb {unused}
// Belgium {unused}
// Belize {unused}
// Bermuda {unused}
// Brazil {unused}
// Bulg {unused}
// C-Eur {unused}
// CA {unused}
// CO {unused}
// CR {unused}
// Chatham {unused}
// Chicago {unused}
// Chile {unused}
// Cook {unused}
// Cuba {unused}
// Cyprus {unused}
// Czech {unused}
// DR {unused}
// Denver {unused}
// Detroit {unused}
// Dhaka {unused}
// E-Eur {unused}
// E-EurAsia {unused}
// EUAsia {unused}
// Ecuador {unused}
// Egypt {unused}
// EgyptAsia {unused}
// Eire {unused}
// Falk {unused}
// Fiji {unused}
// Finland {unused}
// France {unused}
// GB-Eire {unused}
// Germany {unused}
// Greece {unused}
// Guam {unused}
// Guat {unused}
// HK {unused}
// Haiti {unused}
// Halifax {unused}
// Holiday {unused}
// Hond {unused}
// Hungary {unused}
// Indianapolis {unused}
// Iran {unused}
// Iraq {unused}
// Italy {unused}
// Japan {unused}
// Jordan {unused}
// Kyrgyz {unused}
// LH {unused}
// Latvia {unused}
// Lebanon {unused}
// Libya {unused}
// Louisville {unused}
// Macau {unused}
// Malta {unused}
// Marengo {unused}
// Mauritius {unused}
// Menominee {unused}
// Mexico {unused}
// Moldova {unused}
// Moncton {unused}
// Mongol {unused}
// NBorneo {unused}
// NC {unused}
// NT_YK {unused}
// NYC {unused}
// NZ {unused}
// Nic {unused}
// PRC {unused}
// Pakistan {unused}
// Palestine {unused}
// Para {unused}
// Perry {unused}
// Peru {unused}
// Phil {unused}
// Pike {unused}
// Poland {unused}
// Pulaski {unused}
// ROK {unused}
// Regina {unused}
// Romania {unused}
// Russia {unused}
// RussiaAsia {unused}
// SA {unused}
// Salv {unused}
// SanLuis {unused}
// Shang {unused}
// SovietZone {unused}
// Spain {unused}
// SpainAfrica {unused}
// StJohns {unused}
// Starke {unused}
// Sudan {unused}
// Swift {unused}
// Swiss {unused}
// Syria {unused}
// Taiwan {unused}
// Thule {unused}
// Tonga {unused}
// Toronto {unused}
// Troll {unused}
// Tunisia {unused}
// Turkey {unused}
// Uruguay {unused}
// Vanuatu {unused}
// Vincennes {unused}
// Yukon {unused}
// Zion {unused}


//---------------------------------------------------------------------------
// Notable zone policies: 2
//---------------------------------------------------------------------------

// Morocco {SAVE '-1:00' is a negative DST}
// Namibia {
//   LETTER 'CAT' not single character,
//   LETTER 'WAT' not single character,
//   SAVE '-1:00' is a negative DST,
// }


}
}

#endif
