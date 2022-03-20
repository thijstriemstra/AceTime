// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/dev/tz
//     --output_dir /home/brian/src/AceTime/src/ace_time/zonedb
//     --tz_version 2022a
//     --action zonedb
//     --language arduino
//     --scope basic
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
// from https://github.com/eggert/tz/releases/tag/2022a
//
// DO NOT EDIT

#ifndef ACE_TIME_ZONEDB_ZONE_POLICIES_H
#define ACE_TIME_ZONEDB_ZONE_POLICIES_H

#include <ace_time/internal/ZonePolicy.h>

namespace ace_time {
namespace zonedb {

//---------------------------------------------------------------------------
// Supported zone policies: 64
//---------------------------------------------------------------------------

extern const basic::ZonePolicy kPolicyAN;
extern const basic::ZonePolicy kPolicyAQ;
extern const basic::ZonePolicy kPolicyAS;
extern const basic::ZonePolicy kPolicyAT;
extern const basic::ZonePolicy kPolicyAV;
extern const basic::ZonePolicy kPolicyAW;
extern const basic::ZonePolicy kPolicyArmenia;
extern const basic::ZonePolicy kPolicyAus;
extern const basic::ZonePolicy kPolicyAzer;
extern const basic::ZonePolicy kPolicyBarb;
extern const basic::ZonePolicy kPolicyBrazil;
extern const basic::ZonePolicy kPolicyC_Eur;
extern const basic::ZonePolicy kPolicyCO;
extern const basic::ZonePolicy kPolicyCR;
extern const basic::ZonePolicy kPolicyCanada;
extern const basic::ZonePolicy kPolicyChatham;
extern const basic::ZonePolicy kPolicyChile;
extern const basic::ZonePolicy kPolicyCook;
extern const basic::ZonePolicy kPolicyCuba;
extern const basic::ZonePolicy kPolicyDhaka;
extern const basic::ZonePolicy kPolicyEU;
extern const basic::ZonePolicy kPolicyEUAsia;
extern const basic::ZonePolicy kPolicyEcuador;
extern const basic::ZonePolicy kPolicyEire;
extern const basic::ZonePolicy kPolicyFiji;
extern const basic::ZonePolicy kPolicyGuat;
extern const basic::ZonePolicy kPolicyHK;
extern const basic::ZonePolicy kPolicyHaiti;
extern const basic::ZonePolicy kPolicyHoliday;
extern const basic::ZonePolicy kPolicyHond;
extern const basic::ZonePolicy kPolicyIran;
extern const basic::ZonePolicy kPolicyIraq;
extern const basic::ZonePolicy kPolicyJapan;
extern const basic::ZonePolicy kPolicyJordan;
extern const basic::ZonePolicy kPolicyLH;
extern const basic::ZonePolicy kPolicyLebanon;
extern const basic::ZonePolicy kPolicyMacau;
extern const basic::ZonePolicy kPolicyMauritius;
extern const basic::ZonePolicy kPolicyMexico;
extern const basic::ZonePolicy kPolicyMoldova;
extern const basic::ZonePolicy kPolicyMoncton;
extern const basic::ZonePolicy kPolicyMongol;
extern const basic::ZonePolicy kPolicyNC;
extern const basic::ZonePolicy kPolicyNZ;
extern const basic::ZonePolicy kPolicyNic;
extern const basic::ZonePolicy kPolicyPRC;
extern const basic::ZonePolicy kPolicyPakistan;
extern const basic::ZonePolicy kPolicyPara;
extern const basic::ZonePolicy kPolicyPeru;
extern const basic::ZonePolicy kPolicyPhil;
extern const basic::ZonePolicy kPolicyROK;
extern const basic::ZonePolicy kPolicyRussiaAsia;
extern const basic::ZonePolicy kPolicySA;
extern const basic::ZonePolicy kPolicySalv;
extern const basic::ZonePolicy kPolicySyria;
extern const basic::ZonePolicy kPolicyTaiwan;
extern const basic::ZonePolicy kPolicyThule;
extern const basic::ZonePolicy kPolicyTonga;
extern const basic::ZonePolicy kPolicyTunisia;
extern const basic::ZonePolicy kPolicyUS;
extern const basic::ZonePolicy kPolicyUruguay;
extern const basic::ZonePolicy kPolicyVanuatu;
extern const basic::ZonePolicy kPolicyWinn;
extern const basic::ZonePolicy kPolicyZion;


//---------------------------------------------------------------------------
// Unsupported zone policies: 74
//---------------------------------------------------------------------------

// Albania (unused)
// Algeria (unused)
// Arg (unused)
// Austria (unused)
// Belgium (unused)
// Belize (LETTER 'CST' too long)
// Bermuda (unused)
// Bulg (unused)
// CA (unused)
// Chicago (unused)
// Cyprus (unused)
// Czech (unused)
// DR (unused)
// Denmark (unused)
// Denver (unused)
// Detroit (unused)
// E-Eur (unused)
// E-EurAsia (unused)
// Edm (unused)
// Egypt (Found 2 transitions in year/month '2010-09')
// EgyptAsia (unused)
// Falk (unused)
// Finland (unused)
// France (unused)
// GB-Eire (unused)
// Germany (unused)
// Greece (unused)
// Guam (unused)
// Halifax (unused)
// Hungary (unused)
// Iceland (unused)
// Indianapolis (unused)
// Italy (unused)
// Kyrgyz (unused)
// Latvia (unused)
// Libya (unused)
// Louisville (unused)
// Lux (unused)
// Malta (unused)
// Marengo (unused)
// Menominee (unused)
// Morocco (unused)
// NBorneo (unused)
// NT_YK (unused)
// NYC (unused)
// Namibia (LETTER 'WAT' too long)
// Neth (unused)
// Norway (unused)
// Palestine (Found 2 transitions in year/month '2011-08')
// Perry (unused)
// Pike (unused)
// Poland (unused)
// Port (unused)
// Pulaski (unused)
// Regina (unused)
// Romania (unused)
// Russia (unused)
// SanLuis (unused)
// Shang (unused)
// SovietZone (unused)
// Spain (unused)
// SpainAfrica (unused)
// StJohns (unused)
// Starke (unused)
// Sudan (unused)
// Swift (unused)
// Swiss (unused)
// Toronto (unused)
// Troll (unused)
// Turkey (unused)
// Vanc (unused)
// Vincennes (unused)
// W-Eur (unused)
// WS (unused)


//---------------------------------------------------------------------------
// Notable zone policies: 4
//---------------------------------------------------------------------------

// Eire (SAVE (delta_offset) '-1:00' different from 1:00)
// LH (SAVE (delta_offset) '0:30' different from 1:00)
// Moncton (AT '0:01' not on 15-minute boundary)
// Namibia (SAVE (delta_offset) '-1:00' different from 1:00)


}
}

#endif
