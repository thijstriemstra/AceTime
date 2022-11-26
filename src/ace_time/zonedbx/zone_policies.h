// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/dev/tz
//     --output_dir /home/brian/src/AceTime/src/ace_time/zonedbx
//     --tz_version 2022f
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
// from https://github.com/eggert/tz/releases/tag/2022f
//
// DO NOT EDIT

#ifndef ACE_TIME_ZONEDBX_ZONE_POLICIES_H
#define ACE_TIME_ZONEDBX_ZONE_POLICIES_H

#include <ace_time/internal/ZonePolicy.h>

namespace ace_time {
namespace zonedbx {

//---------------------------------------------------------------------------
// Supported zone policies: 83
//---------------------------------------------------------------------------

extern const extended::ZonePolicy kPolicyAN;
extern const extended::ZonePolicy kPolicyAQ;
extern const extended::ZonePolicy kPolicyAS;
extern const extended::ZonePolicy kPolicyAT;
extern const extended::ZonePolicy kPolicyAV;
extern const extended::ZonePolicy kPolicyAW;
extern const extended::ZonePolicy kPolicyArg;
extern const extended::ZonePolicy kPolicyArmenia;
extern const extended::ZonePolicy kPolicyAus;
extern const extended::ZonePolicy kPolicyAzer;
extern const extended::ZonePolicy kPolicyBarb;
extern const extended::ZonePolicy kPolicyBelize;
extern const extended::ZonePolicy kPolicyBrazil;
extern const extended::ZonePolicy kPolicyC_Eur;
extern const extended::ZonePolicy kPolicyCO;
extern const extended::ZonePolicy kPolicyCR;
extern const extended::ZonePolicy kPolicyCanada;
extern const extended::ZonePolicy kPolicyChatham;
extern const extended::ZonePolicy kPolicyChile;
extern const extended::ZonePolicy kPolicyCook;
extern const extended::ZonePolicy kPolicyCuba;
extern const extended::ZonePolicy kPolicyDhaka;
extern const extended::ZonePolicy kPolicyE_EurAsia;
extern const extended::ZonePolicy kPolicyEU;
extern const extended::ZonePolicy kPolicyEUAsia;
extern const extended::ZonePolicy kPolicyEcuador;
extern const extended::ZonePolicy kPolicyEgypt;
extern const extended::ZonePolicy kPolicyEire;
extern const extended::ZonePolicy kPolicyFalk;
extern const extended::ZonePolicy kPolicyFiji;
extern const extended::ZonePolicy kPolicyGuam;
extern const extended::ZonePolicy kPolicyGuat;
extern const extended::ZonePolicy kPolicyHK;
extern const extended::ZonePolicy kPolicyHaiti;
extern const extended::ZonePolicy kPolicyHoliday;
extern const extended::ZonePolicy kPolicyHond;
extern const extended::ZonePolicy kPolicyIran;
extern const extended::ZonePolicy kPolicyIraq;
extern const extended::ZonePolicy kPolicyJapan;
extern const extended::ZonePolicy kPolicyJordan;
extern const extended::ZonePolicy kPolicyKyrgyz;
extern const extended::ZonePolicy kPolicyLH;
extern const extended::ZonePolicy kPolicyLebanon;
extern const extended::ZonePolicy kPolicyLibya;
extern const extended::ZonePolicy kPolicyMacau;
extern const extended::ZonePolicy kPolicyMauritius;
extern const extended::ZonePolicy kPolicyMexico;
extern const extended::ZonePolicy kPolicyMoldova;
extern const extended::ZonePolicy kPolicyMoncton;
extern const extended::ZonePolicy kPolicyMongol;
extern const extended::ZonePolicy kPolicyMorocco;
extern const extended::ZonePolicy kPolicyNC;
extern const extended::ZonePolicy kPolicyNT_YK;
extern const extended::ZonePolicy kPolicyNZ;
extern const extended::ZonePolicy kPolicyNamibia;
extern const extended::ZonePolicy kPolicyNic;
extern const extended::ZonePolicy kPolicyPRC;
extern const extended::ZonePolicy kPolicyPakistan;
extern const extended::ZonePolicy kPolicyPalestine;
extern const extended::ZonePolicy kPolicyPara;
extern const extended::ZonePolicy kPolicyPeru;
extern const extended::ZonePolicy kPolicyPhil;
extern const extended::ZonePolicy kPolicyROK;
extern const extended::ZonePolicy kPolicyRussia;
extern const extended::ZonePolicy kPolicyRussiaAsia;
extern const extended::ZonePolicy kPolicySA;
extern const extended::ZonePolicy kPolicySalv;
extern const extended::ZonePolicy kPolicySanLuis;
extern const extended::ZonePolicy kPolicyStJohns;
extern const extended::ZonePolicy kPolicySudan;
extern const extended::ZonePolicy kPolicySyria;
extern const extended::ZonePolicy kPolicyTaiwan;
extern const extended::ZonePolicy kPolicyThule;
extern const extended::ZonePolicy kPolicyTonga;
extern const extended::ZonePolicy kPolicyTroll;
extern const extended::ZonePolicy kPolicyTunisia;
extern const extended::ZonePolicy kPolicyTurkey;
extern const extended::ZonePolicy kPolicyUS;
extern const extended::ZonePolicy kPolicyUruguay;
extern const extended::ZonePolicy kPolicyVanuatu;
extern const extended::ZonePolicy kPolicyWS;
extern const extended::ZonePolicy kPolicyWinn;
extern const extended::ZonePolicy kPolicyZion;


//---------------------------------------------------------------------------
// Unsupported zone policies: 50
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


//---------------------------------------------------------------------------
// Notable zone policies: 15
//---------------------------------------------------------------------------

// Armenia {Added anchor rule at year 0}
// Belize {LETTER 'CST' not single character}
// Dhaka {Added anchor rule at year 0}
// Eire {SAVE (delta_offset) '-1:00' different from 1:00}
// LH {SAVE (delta_offset) '0:30' different from 1:00}
// Moncton {AT '0:01' not on 15-minute boundary}
// Morocco {SAVE (delta_offset) '-1:00' different from 1:00}
// Namibia {
//   LETTER 'CAT' not single character,
//   LETTER 'WAT' not single character,
//   SAVE (delta_offset) '-1:00' different from 1:00,
// }
// Pakistan {Added anchor rule at year 0}
// Palestine {
//   AT '0:01' not on 15-minute boundary,
//   Added anchor rule at year 0,
// }
// SanLuis {Added anchor rule at year 0}
// StJohns {
//   AT '0:01' not on 15-minute boundary,
//   LETTER 'DD' not single character,
//   SAVE (delta_offset) '2:00' different from 1:00,
// }
// Tonga {Added anchor rule at year 0}
// Troll {
//   Added anchor rule at year 0,
//   LETTER '+00' not single character,
//   LETTER '+02' not single character,
//   SAVE (delta_offset) '2:00' different from 1:00,
// }
// WS {Added anchor rule at year 0}


}
}

#endif
