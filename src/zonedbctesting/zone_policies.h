// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/zonedbctesting/tzfiles
//     --output_dir /home/brian/src/AceTime/src/zonedbctesting
//     --tz_version 2023c
//     --action zonedb
//     --language arduino
//     --scope complete
//     --db_namespace zonedbctesting
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
// Lower/Upper Truncated: [True, False]
//
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
//   Context: 16
//   Rules: 2724
//   Policies: 36
//   Eras: 450
//   Zones: 195
//   Links: 13
//   Registry: 32
//   Formats: 92
//   Letters: 23
//   Fragments: 0
//   Names: 260 (original: 260)
//   TOTAL: 3841
//
// Memory (32-bits):
//   Context: 24
//   Rules: 2724
//   Policies: 96
//   Eras: 600
//   Zones: 360
//   Links: 24
//   Registry: 64
//   Formats: 92
//   Letters: 33
//   Fragments: 0
//   Names: 260 (original: 260)
//   TOTAL: 4277
//
// DO NOT EDIT

#ifndef ACE_TIME_ZONEDBCTESTING_ZONE_POLICIES_H
#define ACE_TIME_ZONEDBCTESTING_ZONE_POLICIES_H

#include <zoneinfo/infos.h>

namespace ace_time {
namespace zonedbctesting {

//---------------------------------------------------------------------------
// Supported policies: 12
//---------------------------------------------------------------------------

extern const complete::ZonePolicy kZonePolicyAus;
extern const complete::ZonePolicy kZonePolicyCanada;
extern const complete::ZonePolicy kZonePolicyEU;
extern const complete::ZonePolicy kZonePolicyEdm;
extern const complete::ZonePolicy kZonePolicyMorocco;
extern const complete::ZonePolicy kZonePolicyNamibia;
extern const complete::ZonePolicy kZonePolicyPort;
extern const complete::ZonePolicy kZonePolicyUS;
extern const complete::ZonePolicy kZonePolicyVanc;
extern const complete::ZonePolicy kZonePolicyW_Eur;
extern const complete::ZonePolicy kZonePolicyWS;
extern const complete::ZonePolicy kZonePolicyWinn;


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
