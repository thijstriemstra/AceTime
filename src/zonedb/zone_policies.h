// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/zonedb/tzfiles
//     --output_dir /home/brian/src/AceTime/src/zonedb
//     --tz_version 2022g
//     --action zonedb
//     --language arduino
//     --scope basic
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
// Supported Zones: 446 (227 zones, 219 links)
// Unsupported Zones: 150 (124 zones, 26 links)
// Original Years:  [1844,2087]
// Generated Years: [1950,2023]
// Estimator Years: [1950,2025]
// Max Buffer Size: 6
//
// Memory (8-bits):
//   Rules: 3982
//   Policies: 189
//   Eras: 2868
//   Zones: 2951
//   Links: 2847
//   Registry: 892
//   Formats: 465
//   Letters: 11
//   Fragments: 116
//   Names: 4144 (original: 6503)
//   TOTAL: 18465
//
// Memory (32-bits):
//   Rules: 4344
//   Policies: 504
//   Eras: 3824
//   Zones: 5448
//   Links: 5256
//   Registry: 1784
//   Formats: 465
//   Letters: 17
//   Fragments: 138
//   Names: 4144 (original: 6503)
//   TOTAL: 25924
//
// DO NOT EDIT

#ifndef ACE_TIME_ZONEDB_ZONE_POLICIES_H
#define ACE_TIME_ZONEDB_ZONE_POLICIES_H

#include <zoneinfo/ZonePolicy.h>

namespace ace_time {
namespace zonedb {

//---------------------------------------------------------------------------
// Supported policies: 63
// Supported rules: 362
//---------------------------------------------------------------------------

extern const basic::ZonePolicy kZonePolicyAN;
extern const basic::ZonePolicy kZonePolicyAQ;
extern const basic::ZonePolicy kZonePolicyAS;
extern const basic::ZonePolicy kZonePolicyAT;
extern const basic::ZonePolicy kZonePolicyAV;
extern const basic::ZonePolicy kZonePolicyAW;
extern const basic::ZonePolicy kZonePolicyArmenia;
extern const basic::ZonePolicy kZonePolicyAus;
extern const basic::ZonePolicy kZonePolicyAzer;
extern const basic::ZonePolicy kZonePolicyBarb;
extern const basic::ZonePolicy kZonePolicyBrazil;
extern const basic::ZonePolicy kZonePolicyC_Eur;
extern const basic::ZonePolicy kZonePolicyCO;
extern const basic::ZonePolicy kZonePolicyCR;
extern const basic::ZonePolicy kZonePolicyCanada;
extern const basic::ZonePolicy kZonePolicyChatham;
extern const basic::ZonePolicy kZonePolicyChile;
extern const basic::ZonePolicy kZonePolicyCook;
extern const basic::ZonePolicy kZonePolicyCuba;
extern const basic::ZonePolicy kZonePolicyDhaka;
extern const basic::ZonePolicy kZonePolicyEU;
extern const basic::ZonePolicy kZonePolicyEUAsia;
extern const basic::ZonePolicy kZonePolicyEcuador;
extern const basic::ZonePolicy kZonePolicyEire;
extern const basic::ZonePolicy kZonePolicyFiji;
extern const basic::ZonePolicy kZonePolicyGuat;
extern const basic::ZonePolicy kZonePolicyHK;
extern const basic::ZonePolicy kZonePolicyHaiti;
extern const basic::ZonePolicy kZonePolicyHoliday;
extern const basic::ZonePolicy kZonePolicyHond;
extern const basic::ZonePolicy kZonePolicyIran;
extern const basic::ZonePolicy kZonePolicyIraq;
extern const basic::ZonePolicy kZonePolicyJapan;
extern const basic::ZonePolicy kZonePolicyJordan;
extern const basic::ZonePolicy kZonePolicyLH;
extern const basic::ZonePolicy kZonePolicyLebanon;
extern const basic::ZonePolicy kZonePolicyMacau;
extern const basic::ZonePolicy kZonePolicyMauritius;
extern const basic::ZonePolicy kZonePolicyMexico;
extern const basic::ZonePolicy kZonePolicyMoldova;
extern const basic::ZonePolicy kZonePolicyMoncton;
extern const basic::ZonePolicy kZonePolicyMongol;
extern const basic::ZonePolicy kZonePolicyNC;
extern const basic::ZonePolicy kZonePolicyNZ;
extern const basic::ZonePolicy kZonePolicyNic;
extern const basic::ZonePolicy kZonePolicyPRC;
extern const basic::ZonePolicy kZonePolicyPakistan;
extern const basic::ZonePolicy kZonePolicyPara;
extern const basic::ZonePolicy kZonePolicyPeru;
extern const basic::ZonePolicy kZonePolicyPhil;
extern const basic::ZonePolicy kZonePolicyROK;
extern const basic::ZonePolicy kZonePolicyRussiaAsia;
extern const basic::ZonePolicy kZonePolicySA;
extern const basic::ZonePolicy kZonePolicySalv;
extern const basic::ZonePolicy kZonePolicyTaiwan;
extern const basic::ZonePolicy kZonePolicyThule;
extern const basic::ZonePolicy kZonePolicyTonga;
extern const basic::ZonePolicy kZonePolicyTunisia;
extern const basic::ZonePolicy kZonePolicyUS;
extern const basic::ZonePolicy kZonePolicyUruguay;
extern const basic::ZonePolicy kZonePolicyVanuatu;
extern const basic::ZonePolicy kZonePolicyWinn;
extern const basic::ZonePolicy kZonePolicyZion;


//---------------------------------------------------------------------------
// Unsupported policies: 71
//---------------------------------------------------------------------------

// Albania {unused}
// Algeria {unused}
// Arg {unused}
// Austria {unused}
// Belgium {unused}
// Belize {LETTER 'CST' too long}
// Bermuda {unused}
// Bulg {unused}
// CA {unused}
// Chicago {unused}
// Cyprus {unused}
// Czech {unused}
// DR {unused}
// Denver {unused}
// Detroit {unused}
// E-Eur {unused}
// E-EurAsia {unused}
// Edm {unused}
// Egypt {Found 2 transitions in year/month '2010-09'}
// EgyptAsia {unused}
// Falk {unused}
// Finland {unused}
// France {unused}
// GB-Eire {unused}
// Germany {unused}
// Greece {unused}
// Guam {unused}
// Halifax {unused}
// Hungary {unused}
// Indianapolis {unused}
// Italy {unused}
// Kyrgyz {unused}
// Latvia {unused}
// Libya {unused}
// Louisville {unused}
// Malta {unused}
// Marengo {unused}
// Menominee {unused}
// Morocco {unused}
// NBorneo {unused}
// NT_YK {unused}
// NYC {unused}
// Namibia {LETTER 'CAT' too long}
// Palestine {Found 2 transitions in year/month '2011-08'}
// Perry {unused}
// Pike {unused}
// Poland {unused}
// Port {unused}
// Pulaski {unused}
// Regina {unused}
// Romania {unused}
// Russia {unused}
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
// Toronto {unused}
// Troll {unused}
// Turkey {unused}
// Vanc {unused}
// Vincennes {unused}
// W-Eur {unused}
// WS {unused}
// Yukon {unused}


//---------------------------------------------------------------------------
// Notable zone policies: 4
//---------------------------------------------------------------------------

// Eire {SAVE '-1:00' different from 1:00}
// LH {SAVE '0:30' different from 1:00}
// Moncton {AT '0:01' not on 15-minute boundary}
// Namibia {SAVE '-1:00' different from 1:00}


}
}

#endif
