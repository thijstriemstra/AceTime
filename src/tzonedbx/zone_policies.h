// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/tzonedbx/tzfiles
//     --output_dir /home/brian/src/AceTime/src/tzonedbx
//     --tz_version 2022g
//     --action zonedb
//     --language arduino
//     --scope extended
//     --db_namespace tzonedbx
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
// Supported Zones: 16 (15 zones, 1 links)
// Unsupported Zones: 580 (336 zones, 244 links)
// Original Years: [1844,2087]
// Generated Years: [1943,2087]
//
// DO NOT EDIT

#ifndef ACE_TIME_TZONEDBX_ZONE_POLICIES_H
#define ACE_TIME_TZONEDBX_ZONE_POLICIES_H

#include <ace_time/internal/ZonePolicy.h>

namespace ace_time {
namespace tzonedbx {

//---------------------------------------------------------------------------
// Supported zone policies: 12
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
// Unsupported zone policies: 122
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
// Notable zone policies: 3
//---------------------------------------------------------------------------

// Morocco {SAVE (delta_offset) '-1:00' different from 1:00}
// Namibia {
//   Added anchor rule at year 0,
//   LETTER 'CAT' not single character,
//   LETTER 'WAT' not single character,
//   SAVE (delta_offset) '-1:00' different from 1:00,
// }
// WS {Added anchor rule at year 0}


}
}

#endif
