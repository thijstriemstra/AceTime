// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/zonedbx/tzfiles
//     --output_dir /home/brian/src/AceTime/src/zonedbx
//     --tz_version 2023b
//     --action zonedb
//     --language arduino
//     --scope extended
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
// from https://github.com/eggert/tz/releases/tag/2023b
//
// Supported Zones: 596 (350 zones, 246 links)
// Unsupported Zones: 0 (0 zones, 0 links)
//
// Original Years:  [1844,2087]
// Generated Years: [1950,2087]
// Estimator Years: [1950,2090]
// Max Buffer Size: 7
//
// Records:
//   Infos: 596
//   Eras: 646
//   Policies: 83
//   Rules: 737
//
// Memory (8-bits):
//   Rules: 8107
//   Policies: 249
//   Eras: 7752
//   Zones: 4550
//   Links: 3198
//   Registry: 1192
//   Formats: 597
//   Letters: 46
//   Fragments: 150
//   Names: 5649 (original: 9076)
//   TOTAL: 31490
//
// Memory (32-bits):
//   Rules: 8844
//   Policies: 664
//   Eras: 10336
//   Zones: 8400
//   Links: 5904
//   Registry: 2384
//   Formats: 597
//   Letters: 64
//   Fragments: 178
//   Names: 5649 (original: 9076)
//   TOTAL: 43020
//
// DO NOT EDIT

#ifndef ACE_TIME_ZONEDBX_ZONE_POLICIES_H
#define ACE_TIME_ZONEDBX_ZONE_POLICIES_H

#include <zoneinfo/ZonePolicy.h>

namespace ace_time {
namespace zonedbx {

//---------------------------------------------------------------------------
// Supported policies: 83
// Supported rules: 737
//---------------------------------------------------------------------------

extern const extended::ZonePolicy kZonePolicyAN;
extern const extended::ZonePolicy kZonePolicyAQ;
extern const extended::ZonePolicy kZonePolicyAS;
extern const extended::ZonePolicy kZonePolicyAT;
extern const extended::ZonePolicy kZonePolicyAV;
extern const extended::ZonePolicy kZonePolicyAW;
extern const extended::ZonePolicy kZonePolicyArg;
extern const extended::ZonePolicy kZonePolicyArmenia;
extern const extended::ZonePolicy kZonePolicyAus;
extern const extended::ZonePolicy kZonePolicyAzer;
extern const extended::ZonePolicy kZonePolicyBarb;
extern const extended::ZonePolicy kZonePolicyBelize;
extern const extended::ZonePolicy kZonePolicyBrazil;
extern const extended::ZonePolicy kZonePolicyC_Eur;
extern const extended::ZonePolicy kZonePolicyCO;
extern const extended::ZonePolicy kZonePolicyCR;
extern const extended::ZonePolicy kZonePolicyCanada;
extern const extended::ZonePolicy kZonePolicyChatham;
extern const extended::ZonePolicy kZonePolicyChile;
extern const extended::ZonePolicy kZonePolicyCook;
extern const extended::ZonePolicy kZonePolicyCuba;
extern const extended::ZonePolicy kZonePolicyDhaka;
extern const extended::ZonePolicy kZonePolicyE_EurAsia;
extern const extended::ZonePolicy kZonePolicyEU;
extern const extended::ZonePolicy kZonePolicyEUAsia;
extern const extended::ZonePolicy kZonePolicyEcuador;
extern const extended::ZonePolicy kZonePolicyEgypt;
extern const extended::ZonePolicy kZonePolicyEire;
extern const extended::ZonePolicy kZonePolicyFalk;
extern const extended::ZonePolicy kZonePolicyFiji;
extern const extended::ZonePolicy kZonePolicyGuam;
extern const extended::ZonePolicy kZonePolicyGuat;
extern const extended::ZonePolicy kZonePolicyHK;
extern const extended::ZonePolicy kZonePolicyHaiti;
extern const extended::ZonePolicy kZonePolicyHoliday;
extern const extended::ZonePolicy kZonePolicyHond;
extern const extended::ZonePolicy kZonePolicyIran;
extern const extended::ZonePolicy kZonePolicyIraq;
extern const extended::ZonePolicy kZonePolicyJapan;
extern const extended::ZonePolicy kZonePolicyJordan;
extern const extended::ZonePolicy kZonePolicyKyrgyz;
extern const extended::ZonePolicy kZonePolicyLH;
extern const extended::ZonePolicy kZonePolicyLebanon;
extern const extended::ZonePolicy kZonePolicyLibya;
extern const extended::ZonePolicy kZonePolicyMacau;
extern const extended::ZonePolicy kZonePolicyMauritius;
extern const extended::ZonePolicy kZonePolicyMexico;
extern const extended::ZonePolicy kZonePolicyMoldova;
extern const extended::ZonePolicy kZonePolicyMoncton;
extern const extended::ZonePolicy kZonePolicyMongol;
extern const extended::ZonePolicy kZonePolicyMorocco;
extern const extended::ZonePolicy kZonePolicyNC;
extern const extended::ZonePolicy kZonePolicyNT_YK;
extern const extended::ZonePolicy kZonePolicyNZ;
extern const extended::ZonePolicy kZonePolicyNamibia;
extern const extended::ZonePolicy kZonePolicyNic;
extern const extended::ZonePolicy kZonePolicyPRC;
extern const extended::ZonePolicy kZonePolicyPakistan;
extern const extended::ZonePolicy kZonePolicyPalestine;
extern const extended::ZonePolicy kZonePolicyPara;
extern const extended::ZonePolicy kZonePolicyPeru;
extern const extended::ZonePolicy kZonePolicyPhil;
extern const extended::ZonePolicy kZonePolicyROK;
extern const extended::ZonePolicy kZonePolicyRussia;
extern const extended::ZonePolicy kZonePolicyRussiaAsia;
extern const extended::ZonePolicy kZonePolicySA;
extern const extended::ZonePolicy kZonePolicySalv;
extern const extended::ZonePolicy kZonePolicySanLuis;
extern const extended::ZonePolicy kZonePolicyStJohns;
extern const extended::ZonePolicy kZonePolicySudan;
extern const extended::ZonePolicy kZonePolicySyria;
extern const extended::ZonePolicy kZonePolicyTaiwan;
extern const extended::ZonePolicy kZonePolicyThule;
extern const extended::ZonePolicy kZonePolicyTonga;
extern const extended::ZonePolicy kZonePolicyTroll;
extern const extended::ZonePolicy kZonePolicyTunisia;
extern const extended::ZonePolicy kZonePolicyTurkey;
extern const extended::ZonePolicy kZonePolicyUS;
extern const extended::ZonePolicy kZonePolicyUruguay;
extern const extended::ZonePolicy kZonePolicyVanuatu;
extern const extended::ZonePolicy kZonePolicyWS;
extern const extended::ZonePolicy kZonePolicyWinn;
extern const extended::ZonePolicy kZonePolicyZion;


//---------------------------------------------------------------------------
// Unsupported policies: 51
//---------------------------------------------------------------------------

// Albania {unused}
// Algeria {unused}
// Austria {unused}
// Belgium {unused}
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
// Edm {unused}
// EgyptAsia {unused}
// Finland {unused}
// France {unused}
// GB-Eire {unused}
// Germany {unused}
// Greece {unused}
// Halifax {unused}
// Hungary {unused}
// Indianapolis {unused}
// Italy {unused}
// Latvia {unused}
// Louisville {unused}
// Malta {unused}
// Marengo {unused}
// Menominee {unused}
// NBorneo {unused}
// NYC {unused}
// Perry {unused}
// Pike {unused}
// Poland {unused}
// Port {unused}
// Pulaski {unused}
// Regina {unused}
// Romania {unused}
// Shang {unused}
// SovietZone {unused}
// Spain {unused}
// SpainAfrica {unused}
// Starke {unused}
// Swift {unused}
// Swiss {unused}
// Toronto {unused}
// Vanc {unused}
// Vincennes {unused}
// W-Eur {unused}
// Yukon {unused}


//---------------------------------------------------------------------------
// Notable zone policies: 9
//---------------------------------------------------------------------------

// Belize {LETTER 'CST' not single character}
// Eire {SAVE '-1:00' different from 1:00}
// LH {SAVE '0:30' different from 1:00}
// Moncton {AT '0:01' not on 15-minute boundary}
// Morocco {SAVE '-1:00' different from 1:00}
// Namibia {
//   LETTER 'CAT' not single character,
//   LETTER 'WAT' not single character,
//   SAVE '-1:00' different from 1:00,
// }
// Palestine {AT '0:01' not on 15-minute boundary}
// StJohns {
//   AT '0:01' not on 15-minute boundary,
//   LETTER 'DD' not single character,
//   SAVE '2:00' different from 1:00,
// }
// Troll {
//   LETTER '+00' not single character,
//   LETTER '+02' not single character,
//   SAVE '2:00' different from 1:00,
// }


}
}

#endif
