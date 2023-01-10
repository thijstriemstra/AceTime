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

#ifndef ACE_TIME_TZONEDBX_ZONE_POLICIES_H
#define ACE_TIME_TZONEDBX_ZONE_POLICIES_H

#include <ace_time/internal/ZonePolicy.h>

namespace ace_time {
namespace tzonedbx {

//---------------------------------------------------------------------------
// Supported zone policies: 2
//---------------------------------------------------------------------------

extern const extended::ZonePolicy kZonePolicyNamibia;
extern const extended::ZonePolicy kZonePolicyUS;


//---------------------------------------------------------------------------
// Unsupported zone policies: 132
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
// Aus {unused}
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
// Canada {unused}
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
// EU {unused}
// EUAsia {unused}
// Ecuador {unused}
// Edm {unused}
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
// Morocco {unused}
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
// Port {unused}
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
// Vanc {unused}
// Vanuatu {unused}
// Vincennes {unused}
// W-Eur {unused}
// WS {unused}
// Winn {unused}
// Yukon {unused}
// Zion {unused}


//---------------------------------------------------------------------------
// Notable zone policies: 1
//---------------------------------------------------------------------------

// Namibia {
//   Added anchor rule at year 0,
//   LETTER 'CAT' not single character,
//   LETTER 'WAT' not single character,
//   SAVE (delta_offset) '-1:00' different from 1:00,
// }


}
}

#endif
