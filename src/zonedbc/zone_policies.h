// This file was generated by the following script:
//
//   $ /home/brian/src/AceTimeTools/src/acetimetools/tzcompiler.py
//     --input_dir /home/brian/src/AceTime/src/zonedbc/tzfiles
//     --output_dir /home/brian/src/AceTime/src/zonedbc
//     --tz_version 2023c
//     --action zonedb
//     --language arduino
//     --scope complete
//     --db_namespace zonedbc
//     --start_year 1800
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
// Supported Zones: 596 (350 zones, 246 links)
// Unsupported Zones: 0 (0 zones, 0 links)
//
// Original Years:  [1844,2087]
// Generated Years: [1844,2087]
// Lower/Upper Truncated: [False, False]
//
// Estimator Years: [1800,2090]
// Max Buffer Size: 8
//
// Records:
//   Infos: 596
//   Eras: 1949
//   Policies: 134
//   Rules: 2238
//
// Memory (8-bits):
//   Context: 16
//   Rules: 26856
//   Policies: 402
//   Eras: 29235
//   Zones: 4550
//   Links: 3198
//   Registry: 1192
//   Formats: 1032
//   Letters: 160
//   Fragments: 150
//   Names: 5649 (original: 9076)
//   TOTAL: 72440
//
// Memory (32-bits):
//   Context: 24
//   Rules: 26856
//   Policies: 1072
//   Eras: 38980
//   Zones: 8400
//   Links: 5904
//   Registry: 2384
//   Formats: 1032
//   Letters: 216
//   Fragments: 178
//   Names: 5649 (original: 9076)
//   TOTAL: 90695
//
// DO NOT EDIT

#ifndef ACE_TIME_ZONEDBC_ZONE_POLICIES_H
#define ACE_TIME_ZONEDBC_ZONE_POLICIES_H

#include <zoneinfo/infos.h>

namespace ace_time {
namespace zonedbc {

//---------------------------------------------------------------------------
// Supported policies: 134
//---------------------------------------------------------------------------

extern const complete::ZonePolicy kZonePolicyAN;
extern const complete::ZonePolicy kZonePolicyAQ;
extern const complete::ZonePolicy kZonePolicyAS;
extern const complete::ZonePolicy kZonePolicyAT;
extern const complete::ZonePolicy kZonePolicyAV;
extern const complete::ZonePolicy kZonePolicyAW;
extern const complete::ZonePolicy kZonePolicyAlbania;
extern const complete::ZonePolicy kZonePolicyAlgeria;
extern const complete::ZonePolicy kZonePolicyArg;
extern const complete::ZonePolicy kZonePolicyArmenia;
extern const complete::ZonePolicy kZonePolicyAus;
extern const complete::ZonePolicy kZonePolicyAustria;
extern const complete::ZonePolicy kZonePolicyAzer;
extern const complete::ZonePolicy kZonePolicyBarb;
extern const complete::ZonePolicy kZonePolicyBelgium;
extern const complete::ZonePolicy kZonePolicyBelize;
extern const complete::ZonePolicy kZonePolicyBermuda;
extern const complete::ZonePolicy kZonePolicyBrazil;
extern const complete::ZonePolicy kZonePolicyBulg;
extern const complete::ZonePolicy kZonePolicyC_Eur;
extern const complete::ZonePolicy kZonePolicyCA;
extern const complete::ZonePolicy kZonePolicyCO;
extern const complete::ZonePolicy kZonePolicyCR;
extern const complete::ZonePolicy kZonePolicyCanada;
extern const complete::ZonePolicy kZonePolicyChatham;
extern const complete::ZonePolicy kZonePolicyChicago;
extern const complete::ZonePolicy kZonePolicyChile;
extern const complete::ZonePolicy kZonePolicyCook;
extern const complete::ZonePolicy kZonePolicyCuba;
extern const complete::ZonePolicy kZonePolicyCyprus;
extern const complete::ZonePolicy kZonePolicyCzech;
extern const complete::ZonePolicy kZonePolicyDR;
extern const complete::ZonePolicy kZonePolicyDenver;
extern const complete::ZonePolicy kZonePolicyDetroit;
extern const complete::ZonePolicy kZonePolicyDhaka;
extern const complete::ZonePolicy kZonePolicyE_Eur;
extern const complete::ZonePolicy kZonePolicyE_EurAsia;
extern const complete::ZonePolicy kZonePolicyEU;
extern const complete::ZonePolicy kZonePolicyEUAsia;
extern const complete::ZonePolicy kZonePolicyEcuador;
extern const complete::ZonePolicy kZonePolicyEdm;
extern const complete::ZonePolicy kZonePolicyEgypt;
extern const complete::ZonePolicy kZonePolicyEgyptAsia;
extern const complete::ZonePolicy kZonePolicyEire;
extern const complete::ZonePolicy kZonePolicyFalk;
extern const complete::ZonePolicy kZonePolicyFiji;
extern const complete::ZonePolicy kZonePolicyFinland;
extern const complete::ZonePolicy kZonePolicyFrance;
extern const complete::ZonePolicy kZonePolicyGB_Eire;
extern const complete::ZonePolicy kZonePolicyGermany;
extern const complete::ZonePolicy kZonePolicyGreece;
extern const complete::ZonePolicy kZonePolicyGuam;
extern const complete::ZonePolicy kZonePolicyGuat;
extern const complete::ZonePolicy kZonePolicyHK;
extern const complete::ZonePolicy kZonePolicyHaiti;
extern const complete::ZonePolicy kZonePolicyHalifax;
extern const complete::ZonePolicy kZonePolicyHoliday;
extern const complete::ZonePolicy kZonePolicyHond;
extern const complete::ZonePolicy kZonePolicyHungary;
extern const complete::ZonePolicy kZonePolicyIndianapolis;
extern const complete::ZonePolicy kZonePolicyIran;
extern const complete::ZonePolicy kZonePolicyIraq;
extern const complete::ZonePolicy kZonePolicyItaly;
extern const complete::ZonePolicy kZonePolicyJapan;
extern const complete::ZonePolicy kZonePolicyJordan;
extern const complete::ZonePolicy kZonePolicyKyrgyz;
extern const complete::ZonePolicy kZonePolicyLH;
extern const complete::ZonePolicy kZonePolicyLatvia;
extern const complete::ZonePolicy kZonePolicyLebanon;
extern const complete::ZonePolicy kZonePolicyLibya;
extern const complete::ZonePolicy kZonePolicyLouisville;
extern const complete::ZonePolicy kZonePolicyMacau;
extern const complete::ZonePolicy kZonePolicyMalta;
extern const complete::ZonePolicy kZonePolicyMarengo;
extern const complete::ZonePolicy kZonePolicyMauritius;
extern const complete::ZonePolicy kZonePolicyMenominee;
extern const complete::ZonePolicy kZonePolicyMexico;
extern const complete::ZonePolicy kZonePolicyMoldova;
extern const complete::ZonePolicy kZonePolicyMoncton;
extern const complete::ZonePolicy kZonePolicyMongol;
extern const complete::ZonePolicy kZonePolicyMorocco;
extern const complete::ZonePolicy kZonePolicyNBorneo;
extern const complete::ZonePolicy kZonePolicyNC;
extern const complete::ZonePolicy kZonePolicyNT_YK;
extern const complete::ZonePolicy kZonePolicyNYC;
extern const complete::ZonePolicy kZonePolicyNZ;
extern const complete::ZonePolicy kZonePolicyNamibia;
extern const complete::ZonePolicy kZonePolicyNic;
extern const complete::ZonePolicy kZonePolicyPRC;
extern const complete::ZonePolicy kZonePolicyPakistan;
extern const complete::ZonePolicy kZonePolicyPalestine;
extern const complete::ZonePolicy kZonePolicyPara;
extern const complete::ZonePolicy kZonePolicyPerry;
extern const complete::ZonePolicy kZonePolicyPeru;
extern const complete::ZonePolicy kZonePolicyPhil;
extern const complete::ZonePolicy kZonePolicyPike;
extern const complete::ZonePolicy kZonePolicyPoland;
extern const complete::ZonePolicy kZonePolicyPort;
extern const complete::ZonePolicy kZonePolicyPulaski;
extern const complete::ZonePolicy kZonePolicyROK;
extern const complete::ZonePolicy kZonePolicyRegina;
extern const complete::ZonePolicy kZonePolicyRomania;
extern const complete::ZonePolicy kZonePolicyRussia;
extern const complete::ZonePolicy kZonePolicyRussiaAsia;
extern const complete::ZonePolicy kZonePolicySA;
extern const complete::ZonePolicy kZonePolicySalv;
extern const complete::ZonePolicy kZonePolicySanLuis;
extern const complete::ZonePolicy kZonePolicyShang;
extern const complete::ZonePolicy kZonePolicySovietZone;
extern const complete::ZonePolicy kZonePolicySpain;
extern const complete::ZonePolicy kZonePolicySpainAfrica;
extern const complete::ZonePolicy kZonePolicyStJohns;
extern const complete::ZonePolicy kZonePolicyStarke;
extern const complete::ZonePolicy kZonePolicySudan;
extern const complete::ZonePolicy kZonePolicySwift;
extern const complete::ZonePolicy kZonePolicySwiss;
extern const complete::ZonePolicy kZonePolicySyria;
extern const complete::ZonePolicy kZonePolicyTaiwan;
extern const complete::ZonePolicy kZonePolicyThule;
extern const complete::ZonePolicy kZonePolicyTonga;
extern const complete::ZonePolicy kZonePolicyToronto;
extern const complete::ZonePolicy kZonePolicyTroll;
extern const complete::ZonePolicy kZonePolicyTunisia;
extern const complete::ZonePolicy kZonePolicyTurkey;
extern const complete::ZonePolicy kZonePolicyUS;
extern const complete::ZonePolicy kZonePolicyUruguay;
extern const complete::ZonePolicy kZonePolicyVanc;
extern const complete::ZonePolicy kZonePolicyVanuatu;
extern const complete::ZonePolicy kZonePolicyVincennes;
extern const complete::ZonePolicy kZonePolicyW_Eur;
extern const complete::ZonePolicy kZonePolicyWS;
extern const complete::ZonePolicy kZonePolicyWinn;
extern const complete::ZonePolicy kZonePolicyYukon;
extern const complete::ZonePolicy kZonePolicyZion;


//---------------------------------------------------------------------------
// Unsupported policies: 0
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// Notable zone policies: 27
//---------------------------------------------------------------------------

// Barb {SAVE '0:30' different from 1:00}
// Belize {
//   LETTER '-0530' not single character,
//   LETTER 'CDT' not single character,
//   LETTER 'CPT' not single character,
//   LETTER 'CST' not single character,
//   LETTER 'CWT' not single character,
//   SAVE '0:30' different from 1:00,
// }
// CA {AT '2:01' not multiple of :15 min}
// Cook {SAVE '0:30' different from 1:00}
// DR {
//   LETTER '-0430' not single character,
//   LETTER 'EDT' not single character,
//   LETTER 'EST' not single character,
//   SAVE '0:30' different from 1:00,
// }
// Eire {SAVE '-1:00' is a negative DST}
// France {SAVE '2:00' different from 1:00}
// GB-Eire {
//   LETTER 'BDST' not single character,
//   LETTER 'BST' not single character,
//   LETTER 'GMT' not single character,
//   SAVE '2:00' different from 1:00,
// }
// Germany {SAVE '2:00' different from 1:00}
// Guam {
//   AT '0:01' not multiple of :15 min,
//   AT '2:01' not multiple of :15 min,
// }
// LH {SAVE '0:30' different from 1:00}
// Louisville {AT '0:01' not multiple of :15 min}
// Moncton {AT '0:01' not multiple of :15 min}
// Morocco {SAVE '-1:00' is a negative DST}
// NBorneo {SAVE '0:20' different from 1:00}
// NZ {SAVE '0:30' different from 1:00}
// Namibia {
//   LETTER 'CAT' not single character,
//   LETTER 'WAT' not single character,
//   SAVE '-1:00' is a negative DST,
// }
// Palestine {AT '0:01' not multiple of :15 min}
// Port {SAVE '2:00' different from 1:00}
// Russia {
//   LETTER '+05' not single character,
//   LETTER 'MDST' not single character,
//   LETTER 'MMT' not single character,
//   LETTER 'MSD' not single character,
//   LETTER 'MSK' not single character,
//   LETTER 'MST' not single character,
//   SAVE '2:00' different from 1:00,
// }
// SovietZone {SAVE '2:00' different from 1:00}
// Spain {SAVE '2:00' different from 1:00}
// StJohns {
//   AT '0:01' not multiple of :15 min,
//   LETTER 'DD' not single character,
//   SAVE '2:00' different from 1:00,
// }
// Troll {
//   LETTER '+00' not single character,
//   LETTER '+02' not single character,
//   SAVE '2:00' different from 1:00,
// }
// Uruguay {
//   SAVE '0:30' different from 1:00,
//   SAVE '1:30' different from 1:00,
// }
// Yukon {
//   LETTER 'DD' not single character,
//   SAVE '2:00' different from 1:00,
// }
// Zion {
//   LETTER 'DD' not single character,
//   SAVE '2:00' different from 1:00,
// }


}
}

#endif
