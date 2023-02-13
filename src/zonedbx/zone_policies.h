// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/zonedbx/tzfiles
//     --output_dir /home/brian/src/AceTime/src/zonedbx
//     --tz_version 2022g
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
// from https://github.com/eggert/tz/releases/tag/2022g
//
// Supported Zones: 596 (351 zones, 245 links)
// Unsupported Zones: 0 (0 zones, 0 links)
// Original Years: [1844,2087]
// Generated Years: [1943,2087]
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
// Unsupported zone policies: 51
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
