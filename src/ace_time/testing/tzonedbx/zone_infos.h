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
// DO NOT EDIT

#ifndef ACE_TIME_TZONEDBX_ZONE_INFOS_H
#define ACE_TIME_TZONEDBX_ZONE_INFOS_H

#include <ace_time/internal/ZoneInfo.h>

namespace ace_time {
namespace tzonedbx {

//---------------------------------------------------------------------------
// ZoneContext (should not be in PROGMEM)
//---------------------------------------------------------------------------

// Version of the TZ Database which generated these files.
extern const char kTzDatabaseVersion[];

// Metadata about the zonedb files.
extern const internal::ZoneContext kZoneContext;

//---------------------------------------------------------------------------
// Supported zones: 14
//---------------------------------------------------------------------------

extern const extended::ZoneInfo kZoneAfrica_Casablanca; // Africa/Casablanca
extern const extended::ZoneInfo kZoneAfrica_Windhoek; // Africa/Windhoek
extern const extended::ZoneInfo kZoneAmerica_Caracas; // America/Caracas
extern const extended::ZoneInfo kZoneAmerica_Chicago; // America/Chicago
extern const extended::ZoneInfo kZoneAmerica_Denver; // America/Denver
extern const extended::ZoneInfo kZoneAmerica_Edmonton; // America/Edmonton
extern const extended::ZoneInfo kZoneAmerica_Los_Angeles; // America/Los_Angeles
extern const extended::ZoneInfo kZoneAmerica_New_York; // America/New_York
extern const extended::ZoneInfo kZoneAmerica_Toronto; // America/Toronto
extern const extended::ZoneInfo kZoneAmerica_Vancouver; // America/Vancouver
extern const extended::ZoneInfo kZoneAmerica_Whitehorse; // America/Whitehorse
extern const extended::ZoneInfo kZoneAmerica_Winnipeg; // America/Winnipeg
extern const extended::ZoneInfo kZoneAustralia_Darwin; // Australia/Darwin
extern const extended::ZoneInfo kZoneEurope_Lisbon; // Europe/Lisbon


// Zone Ids

const uint32_t kZoneIdAfrica_Casablanca = 0xc59f1b33; // Africa/Casablanca
const uint32_t kZoneIdAfrica_Windhoek = 0x789c9bd3; // Africa/Windhoek
const uint32_t kZoneIdAmerica_Caracas = 0x3be064f4; // America/Caracas
const uint32_t kZoneIdAmerica_Chicago = 0x4b92b5d4; // America/Chicago
const uint32_t kZoneIdAmerica_Denver = 0x97d10b2a; // America/Denver
const uint32_t kZoneIdAmerica_Edmonton = 0x6cb9484a; // America/Edmonton
const uint32_t kZoneIdAmerica_Los_Angeles = 0xb7f7e8f2; // America/Los_Angeles
const uint32_t kZoneIdAmerica_New_York = 0x1e2a7654; // America/New_York
const uint32_t kZoneIdAmerica_Toronto = 0x792e851b; // America/Toronto
const uint32_t kZoneIdAmerica_Vancouver = 0x2c6f6b1f; // America/Vancouver
const uint32_t kZoneIdAmerica_Whitehorse = 0x54e0e3e8; // America/Whitehorse
const uint32_t kZoneIdAmerica_Winnipeg = 0x8c7dafc7; // America/Winnipeg
const uint32_t kZoneIdAustralia_Darwin = 0x2876bdff; // Australia/Darwin
const uint32_t kZoneIdEurope_Lisbon = 0x5c00a70b; // Europe/Lisbon


//---------------------------------------------------------------------------
// Supported links: 1
//---------------------------------------------------------------------------

extern const extended::ZoneInfo kZoneUS_Pacific; // US/Pacific -> America/Los_Angeles


// Zone Ids

const uint32_t kZoneIdUS_Pacific = 0xa950f6ab; // US/Pacific


//---------------------------------------------------------------------------
// Maximum size of the Transition buffer in ExtendedZoneProcessor for each zone
// over the given years. Used only in the AceTimeValidation/Extended*Test tests
// for ExtendedZoneProcessor.
//
// MaxBufSize: 7
//---------------------------------------------------------------------------

const uint8_t kZoneBufSizeAfrica_Casablanca = 7;  // Africa/Casablanca in 2013
const uint8_t kZoneBufSizeAfrica_Windhoek = 4;  // Africa/Windhoek in 1994
const uint8_t kZoneBufSizeAmerica_Caracas = 2;  // America/Caracas in 2007
const uint8_t kZoneBufSizeAmerica_Chicago = 6;  // America/Chicago in 2008
const uint8_t kZoneBufSizeAmerica_Denver = 6;  // America/Denver in 2008
const uint8_t kZoneBufSizeAmerica_Edmonton = 6;  // America/Edmonton in 2008
const uint8_t kZoneBufSizeAmerica_Los_Angeles = 6;  // America/Los_Angeles in 2008
const uint8_t kZoneBufSizeAmerica_New_York = 6;  // America/New_York in 2008
const uint8_t kZoneBufSizeAmerica_Toronto = 6;  // America/Toronto in 2008
const uint8_t kZoneBufSizeAmerica_Vancouver = 6;  // America/Vancouver in 2008
const uint8_t kZoneBufSizeAmerica_Whitehorse = 6;  // America/Whitehorse in 2008
const uint8_t kZoneBufSizeAmerica_Winnipeg = 6;  // America/Winnipeg in 2006
const uint8_t kZoneBufSizeAustralia_Darwin = 2;  // Australia/Darwin in 1979
const uint8_t kZoneBufSizeEurope_Lisbon = 6;  // Europe/Lisbon in 1983


//---------------------------------------------------------------------------
// Unsupported zones: 337
//---------------------------------------------------------------------------

// Africa/Abidjan {Zone missing from include list}
// Africa/Algiers {Zone missing from include list}
// Africa/Bissau {Zone missing from include list}
// Africa/Cairo {Zone missing from include list}
// Africa/Ceuta {Zone missing from include list}
// Africa/El_Aaiun {Zone missing from include list}
// Africa/Johannesburg {Zone missing from include list}
// Africa/Juba {Zone missing from include list}
// Africa/Khartoum {Zone missing from include list}
// Africa/Lagos {Zone missing from include list}
// Africa/Maputo {Zone missing from include list}
// Africa/Monrovia {Zone missing from include list}
// Africa/Nairobi {Zone missing from include list}
// Africa/Ndjamena {Zone missing from include list}
// Africa/Sao_Tome {Zone missing from include list}
// Africa/Tripoli {Zone missing from include list}
// Africa/Tunis {Zone missing from include list}
// America/Adak {Zone missing from include list}
// America/Anchorage {Zone missing from include list}
// America/Araguaina {Zone missing from include list}
// America/Argentina/Buenos_Aires {Zone missing from include list}
// America/Argentina/Catamarca {Zone missing from include list}
// America/Argentina/Cordoba {Zone missing from include list}
// America/Argentina/Jujuy {Zone missing from include list}
// America/Argentina/La_Rioja {Zone missing from include list}
// America/Argentina/Mendoza {Zone missing from include list}
// America/Argentina/Rio_Gallegos {Zone missing from include list}
// America/Argentina/Salta {Zone missing from include list}
// America/Argentina/San_Juan {Zone missing from include list}
// America/Argentina/San_Luis {Zone missing from include list}
// America/Argentina/Tucuman {Zone missing from include list}
// America/Argentina/Ushuaia {Zone missing from include list}
// America/Asuncion {Zone missing from include list}
// America/Bahia {Zone missing from include list}
// America/Bahia_Banderas {Zone missing from include list}
// America/Barbados {Zone missing from include list}
// America/Belem {Zone missing from include list}
// America/Belize {Zone missing from include list}
// America/Boa_Vista {Zone missing from include list}
// America/Bogota {Zone missing from include list}
// America/Boise {Zone missing from include list}
// America/Cambridge_Bay {Zone missing from include list}
// America/Campo_Grande {Zone missing from include list}
// America/Cancun {Zone missing from include list}
// America/Cayenne {Zone missing from include list}
// America/Chihuahua {Zone missing from include list}
// America/Ciudad_Juarez {Zone missing from include list}
// America/Costa_Rica {Zone missing from include list}
// America/Cuiaba {Zone missing from include list}
// America/Danmarkshavn {Zone missing from include list}
// America/Dawson {Zone missing from include list}
// America/Dawson_Creek {Zone missing from include list}
// America/Detroit {Zone missing from include list}
// America/Eirunepe {Zone missing from include list}
// America/El_Salvador {Zone missing from include list}
// America/Fort_Nelson {Zone missing from include list}
// America/Fortaleza {Zone missing from include list}
// America/Glace_Bay {Zone missing from include list}
// America/Goose_Bay {Zone missing from include list}
// America/Grand_Turk {Zone missing from include list}
// America/Guatemala {Zone missing from include list}
// America/Guayaquil {Zone missing from include list}
// America/Guyana {Zone missing from include list}
// America/Halifax {Zone missing from include list}
// America/Havana {Zone missing from include list}
// America/Hermosillo {Zone missing from include list}
// America/Indiana/Indianapolis {Zone missing from include list}
// America/Indiana/Knox {Zone missing from include list}
// America/Indiana/Marengo {Zone missing from include list}
// America/Indiana/Petersburg {Zone missing from include list}
// America/Indiana/Tell_City {Zone missing from include list}
// America/Indiana/Vevay {Zone missing from include list}
// America/Indiana/Vincennes {Zone missing from include list}
// America/Indiana/Winamac {Zone missing from include list}
// America/Inuvik {Zone missing from include list}
// America/Iqaluit {Zone missing from include list}
// America/Jamaica {Zone missing from include list}
// America/Juneau {Zone missing from include list}
// America/Kentucky/Louisville {Zone missing from include list}
// America/Kentucky/Monticello {Zone missing from include list}
// America/La_Paz {Zone missing from include list}
// America/Lima {Zone missing from include list}
// America/Maceio {Zone missing from include list}
// America/Managua {Zone missing from include list}
// America/Manaus {Zone missing from include list}
// America/Martinique {Zone missing from include list}
// America/Matamoros {Zone missing from include list}
// America/Mazatlan {Zone missing from include list}
// America/Menominee {Zone missing from include list}
// America/Merida {Zone missing from include list}
// America/Metlakatla {Zone missing from include list}
// America/Mexico_City {Zone missing from include list}
// America/Miquelon {Zone missing from include list}
// America/Moncton {Zone missing from include list}
// America/Monterrey {Zone missing from include list}
// America/Montevideo {Zone missing from include list}
// America/Nome {Zone missing from include list}
// America/Noronha {Zone missing from include list}
// America/North_Dakota/Beulah {Zone missing from include list}
// America/North_Dakota/Center {Zone missing from include list}
// America/North_Dakota/New_Salem {Zone missing from include list}
// America/Nuuk {Zone missing from include list}
// America/Ojinaga {Zone missing from include list}
// America/Panama {Zone missing from include list}
// America/Paramaribo {Zone missing from include list}
// America/Phoenix {Zone missing from include list}
// America/Port-au-Prince {Zone missing from include list}
// America/Porto_Velho {Zone missing from include list}
// America/Puerto_Rico {Zone missing from include list}
// America/Punta_Arenas {Zone missing from include list}
// America/Rankin_Inlet {Zone missing from include list}
// America/Recife {Zone missing from include list}
// America/Regina {Zone missing from include list}
// America/Resolute {Zone missing from include list}
// America/Rio_Branco {Zone missing from include list}
// America/Santarem {Zone missing from include list}
// America/Santiago {Zone missing from include list}
// America/Santo_Domingo {Zone missing from include list}
// America/Sao_Paulo {Zone missing from include list}
// America/Scoresbysund {Zone missing from include list}
// America/Sitka {Zone missing from include list}
// America/St_Johns {Zone missing from include list}
// America/Swift_Current {Zone missing from include list}
// America/Tegucigalpa {Zone missing from include list}
// America/Thule {Zone missing from include list}
// America/Tijuana {Zone missing from include list}
// America/Yakutat {Zone missing from include list}
// America/Yellowknife {Zone missing from include list}
// Antarctica/Casey {Zone missing from include list}
// Antarctica/Davis {Zone missing from include list}
// Antarctica/Macquarie {Zone missing from include list}
// Antarctica/Mawson {Zone missing from include list}
// Antarctica/Palmer {Zone missing from include list}
// Antarctica/Rothera {Zone missing from include list}
// Antarctica/Troll {Zone missing from include list}
// Asia/Almaty {Zone missing from include list}
// Asia/Amman {Zone missing from include list}
// Asia/Anadyr {Zone missing from include list}
// Asia/Aqtau {Zone missing from include list}
// Asia/Aqtobe {Zone missing from include list}
// Asia/Ashgabat {Zone missing from include list}
// Asia/Atyrau {Zone missing from include list}
// Asia/Baghdad {Zone missing from include list}
// Asia/Baku {Zone missing from include list}
// Asia/Bangkok {Zone missing from include list}
// Asia/Barnaul {Zone missing from include list}
// Asia/Beirut {Zone missing from include list}
// Asia/Bishkek {Zone missing from include list}
// Asia/Chita {Zone missing from include list}
// Asia/Choibalsan {Zone missing from include list}
// Asia/Colombo {Zone missing from include list}
// Asia/Damascus {Zone missing from include list}
// Asia/Dhaka {Zone missing from include list}
// Asia/Dili {Zone missing from include list}
// Asia/Dubai {Zone missing from include list}
// Asia/Dushanbe {Zone missing from include list}
// Asia/Famagusta {Zone missing from include list}
// Asia/Gaza {Zone missing from include list}
// Asia/Hebron {Zone missing from include list}
// Asia/Ho_Chi_Minh {Zone missing from include list}
// Asia/Hong_Kong {Zone missing from include list}
// Asia/Hovd {Zone missing from include list}
// Asia/Irkutsk {Zone missing from include list}
// Asia/Jakarta {Zone missing from include list}
// Asia/Jayapura {Zone missing from include list}
// Asia/Jerusalem {Zone missing from include list}
// Asia/Kabul {Zone missing from include list}
// Asia/Kamchatka {Zone missing from include list}
// Asia/Karachi {Zone missing from include list}
// Asia/Kathmandu {Zone missing from include list}
// Asia/Khandyga {Zone missing from include list}
// Asia/Kolkata {Zone missing from include list}
// Asia/Krasnoyarsk {Zone missing from include list}
// Asia/Kuching {Zone missing from include list}
// Asia/Macau {Zone missing from include list}
// Asia/Magadan {Zone missing from include list}
// Asia/Makassar {Zone missing from include list}
// Asia/Manila {Zone missing from include list}
// Asia/Nicosia {Zone missing from include list}
// Asia/Novokuznetsk {Zone missing from include list}
// Asia/Novosibirsk {Zone missing from include list}
// Asia/Omsk {Zone missing from include list}
// Asia/Oral {Zone missing from include list}
// Asia/Pontianak {Zone missing from include list}
// Asia/Pyongyang {Zone missing from include list}
// Asia/Qatar {Zone missing from include list}
// Asia/Qostanay {Zone missing from include list}
// Asia/Qyzylorda {Zone missing from include list}
// Asia/Riyadh {Zone missing from include list}
// Asia/Sakhalin {Zone missing from include list}
// Asia/Samarkand {Zone missing from include list}
// Asia/Seoul {Zone missing from include list}
// Asia/Shanghai {Zone missing from include list}
// Asia/Singapore {Zone missing from include list}
// Asia/Srednekolymsk {Zone missing from include list}
// Asia/Taipei {Zone missing from include list}
// Asia/Tashkent {Zone missing from include list}
// Asia/Tbilisi {Zone missing from include list}
// Asia/Tehran {Zone missing from include list}
// Asia/Thimphu {Zone missing from include list}
// Asia/Tokyo {Zone missing from include list}
// Asia/Tomsk {Zone missing from include list}
// Asia/Ulaanbaatar {Zone missing from include list}
// Asia/Urumqi {Zone missing from include list}
// Asia/Ust-Nera {Zone missing from include list}
// Asia/Vladivostok {Zone missing from include list}
// Asia/Yakutsk {Zone missing from include list}
// Asia/Yangon {Zone missing from include list}
// Asia/Yekaterinburg {Zone missing from include list}
// Asia/Yerevan {Zone missing from include list}
// Atlantic/Azores {Zone missing from include list}
// Atlantic/Bermuda {Zone missing from include list}
// Atlantic/Canary {Zone missing from include list}
// Atlantic/Cape_Verde {Zone missing from include list}
// Atlantic/Faroe {Zone missing from include list}
// Atlantic/Madeira {Zone missing from include list}
// Atlantic/South_Georgia {Zone missing from include list}
// Atlantic/Stanley {Zone missing from include list}
// Australia/Adelaide {Zone missing from include list}
// Australia/Brisbane {Zone missing from include list}
// Australia/Broken_Hill {Zone missing from include list}
// Australia/Eucla {Zone missing from include list}
// Australia/Hobart {Zone missing from include list}
// Australia/Lindeman {Zone missing from include list}
// Australia/Lord_Howe {Zone missing from include list}
// Australia/Melbourne {Zone missing from include list}
// Australia/Perth {Zone missing from include list}
// Australia/Sydney {Zone missing from include list}
// CET {Zone missing from include list}
// CST6CDT {Zone missing from include list}
// EET {Zone missing from include list}
// EST {Zone missing from include list}
// EST5EDT {Zone missing from include list}
// Etc/GMT {Zone missing from include list}
// Etc/GMT+1 {Zone missing from include list}
// Etc/GMT+10 {Zone missing from include list}
// Etc/GMT+11 {Zone missing from include list}
// Etc/GMT+12 {Zone missing from include list}
// Etc/GMT+2 {Zone missing from include list}
// Etc/GMT+3 {Zone missing from include list}
// Etc/GMT+4 {Zone missing from include list}
// Etc/GMT+5 {Zone missing from include list}
// Etc/GMT+6 {Zone missing from include list}
// Etc/GMT+7 {Zone missing from include list}
// Etc/GMT+8 {Zone missing from include list}
// Etc/GMT+9 {Zone missing from include list}
// Etc/GMT-1 {Zone missing from include list}
// Etc/GMT-10 {Zone missing from include list}
// Etc/GMT-11 {Zone missing from include list}
// Etc/GMT-12 {Zone missing from include list}
// Etc/GMT-13 {Zone missing from include list}
// Etc/GMT-14 {Zone missing from include list}
// Etc/GMT-2 {Zone missing from include list}
// Etc/GMT-3 {Zone missing from include list}
// Etc/GMT-4 {Zone missing from include list}
// Etc/GMT-5 {Zone missing from include list}
// Etc/GMT-6 {Zone missing from include list}
// Etc/GMT-7 {Zone missing from include list}
// Etc/GMT-8 {Zone missing from include list}
// Etc/GMT-9 {Zone missing from include list}
// Etc/UTC {Zone missing from include list}
// Europe/Andorra {Zone missing from include list}
// Europe/Astrakhan {Zone missing from include list}
// Europe/Athens {Zone missing from include list}
// Europe/Belgrade {Zone missing from include list}
// Europe/Berlin {Zone missing from include list}
// Europe/Brussels {Zone missing from include list}
// Europe/Bucharest {Zone missing from include list}
// Europe/Budapest {Zone missing from include list}
// Europe/Chisinau {Zone missing from include list}
// Europe/Dublin {Zone missing from include list}
// Europe/Gibraltar {Zone missing from include list}
// Europe/Helsinki {Zone missing from include list}
// Europe/Istanbul {Zone missing from include list}
// Europe/Kaliningrad {Zone missing from include list}
// Europe/Kirov {Zone missing from include list}
// Europe/Kyiv {Zone missing from include list}
// Europe/London {Zone missing from include list}
// Europe/Madrid {Zone missing from include list}
// Europe/Malta {Zone missing from include list}
// Europe/Minsk {Zone missing from include list}
// Europe/Moscow {Zone missing from include list}
// Europe/Paris {Zone missing from include list}
// Europe/Prague {Zone missing from include list}
// Europe/Riga {Zone missing from include list}
// Europe/Rome {Zone missing from include list}
// Europe/Samara {Zone missing from include list}
// Europe/Saratov {Zone missing from include list}
// Europe/Simferopol {Zone missing from include list}
// Europe/Sofia {Zone missing from include list}
// Europe/Tallinn {Zone missing from include list}
// Europe/Tirane {Zone missing from include list}
// Europe/Ulyanovsk {Zone missing from include list}
// Europe/Vienna {Zone missing from include list}
// Europe/Vilnius {Zone missing from include list}
// Europe/Volgograd {Zone missing from include list}
// Europe/Warsaw {Zone missing from include list}
// Europe/Zurich {Zone missing from include list}
// HST {Zone missing from include list}
// Indian/Chagos {Zone missing from include list}
// Indian/Maldives {Zone missing from include list}
// Indian/Mauritius {Zone missing from include list}
// MET {Zone missing from include list}
// MST {Zone missing from include list}
// MST7MDT {Zone missing from include list}
// PST8PDT {Zone missing from include list}
// Pacific/Apia {Zone missing from include list}
// Pacific/Auckland {Zone missing from include list}
// Pacific/Bougainville {Zone missing from include list}
// Pacific/Chatham {Zone missing from include list}
// Pacific/Easter {Zone missing from include list}
// Pacific/Efate {Zone missing from include list}
// Pacific/Fakaofo {Zone missing from include list}
// Pacific/Fiji {Zone missing from include list}
// Pacific/Galapagos {Zone missing from include list}
// Pacific/Gambier {Zone missing from include list}
// Pacific/Guadalcanal {Zone missing from include list}
// Pacific/Guam {Zone missing from include list}
// Pacific/Honolulu {Zone missing from include list}
// Pacific/Kanton {Zone missing from include list}
// Pacific/Kiritimati {Zone missing from include list}
// Pacific/Kosrae {Zone missing from include list}
// Pacific/Kwajalein {Zone missing from include list}
// Pacific/Marquesas {Zone missing from include list}
// Pacific/Nauru {Zone missing from include list}
// Pacific/Niue {Zone missing from include list}
// Pacific/Norfolk {Zone missing from include list}
// Pacific/Noumea {Zone missing from include list}
// Pacific/Pago_Pago {Zone missing from include list}
// Pacific/Palau {Zone missing from include list}
// Pacific/Pitcairn {Zone missing from include list}
// Pacific/Port_Moresby {Zone missing from include list}
// Pacific/Rarotonga {Zone missing from include list}
// Pacific/Tahiti {Zone missing from include list}
// Pacific/Tarawa {Zone missing from include list}
// Pacific/Tongatapu {Zone missing from include list}
// WET {Zone missing from include list}


//---------------------------------------------------------------------------
// Notable zones: 2
//---------------------------------------------------------------------------

// Africa/Casablanca {
//   Morocco {SAVE (delta_offset) '-1:00' different from 1:00}
// }
// Africa/Windhoek {
//   Namibia {
//     Added anchor rule at year 0,
//     LETTER 'CAT' not single character,
//     LETTER 'WAT' not single character,
//     SAVE (delta_offset) '-1:00' different from 1:00,
//   }
// }


//---------------------------------------------------------------------------
// Unsupported links: 244
//---------------------------------------------------------------------------

// Africa/Accra {Link missing from include list}
// Africa/Addis_Ababa {Link missing from include list}
// Africa/Asmara {Link missing from include list}
// Africa/Asmera {Link missing from include list}
// Africa/Bamako {Link missing from include list}
// Africa/Bangui {Link missing from include list}
// Africa/Banjul {Link missing from include list}
// Africa/Blantyre {Link missing from include list}
// Africa/Brazzaville {Link missing from include list}
// Africa/Bujumbura {Link missing from include list}
// Africa/Conakry {Link missing from include list}
// Africa/Dakar {Link missing from include list}
// Africa/Dar_es_Salaam {Link missing from include list}
// Africa/Djibouti {Link missing from include list}
// Africa/Douala {Link missing from include list}
// Africa/Freetown {Link missing from include list}
// Africa/Gaborone {Link missing from include list}
// Africa/Harare {Link missing from include list}
// Africa/Kampala {Link missing from include list}
// Africa/Kigali {Link missing from include list}
// Africa/Kinshasa {Link missing from include list}
// Africa/Libreville {Link missing from include list}
// Africa/Lome {Link missing from include list}
// Africa/Luanda {Link missing from include list}
// Africa/Lubumbashi {Link missing from include list}
// Africa/Lusaka {Link missing from include list}
// Africa/Malabo {Link missing from include list}
// Africa/Maseru {Link missing from include list}
// Africa/Mbabane {Link missing from include list}
// Africa/Mogadishu {Link missing from include list}
// Africa/Niamey {Link missing from include list}
// Africa/Nouakchott {Link missing from include list}
// Africa/Ouagadougou {Link missing from include list}
// Africa/Porto-Novo {Link missing from include list}
// Africa/Timbuktu {Link missing from include list}
// America/Anguilla {Link missing from include list}
// America/Antigua {Link missing from include list}
// America/Argentina/ComodRivadavia {Link missing from include list}
// America/Aruba {Link missing from include list}
// America/Atikokan {Link missing from include list}
// America/Atka {Link missing from include list}
// America/Blanc-Sablon {Link missing from include list}
// America/Buenos_Aires {Link missing from include list}
// America/Catamarca {Link missing from include list}
// America/Cayman {Link missing from include list}
// America/Coral_Harbour {Link missing from include list}
// America/Cordoba {Link missing from include list}
// America/Creston {Link missing from include list}
// America/Curacao {Link missing from include list}
// America/Dominica {Link missing from include list}
// America/Ensenada {Link missing from include list}
// America/Fort_Wayne {Link missing from include list}
// America/Godthab {Link missing from include list}
// America/Grenada {Link missing from include list}
// America/Guadeloupe {Link missing from include list}
// America/Indianapolis {Link missing from include list}
// America/Jujuy {Link missing from include list}
// America/Knox_IN {Link missing from include list}
// America/Kralendijk {Link missing from include list}
// America/Louisville {Link missing from include list}
// America/Lower_Princes {Link missing from include list}
// America/Marigot {Link missing from include list}
// America/Mendoza {Link missing from include list}
// America/Montreal {Link missing from include list}
// America/Montserrat {Link missing from include list}
// America/Nassau {Link missing from include list}
// America/Nipigon {Link missing from include list}
// America/Pangnirtung {Link missing from include list}
// America/Port_of_Spain {Link missing from include list}
// America/Porto_Acre {Link missing from include list}
// America/Rainy_River {Link missing from include list}
// America/Rosario {Link missing from include list}
// America/Santa_Isabel {Link missing from include list}
// America/Shiprock {Link missing from include list}
// America/St_Barthelemy {Link missing from include list}
// America/St_Kitts {Link missing from include list}
// America/St_Lucia {Link missing from include list}
// America/St_Thomas {Link missing from include list}
// America/St_Vincent {Link missing from include list}
// America/Thunder_Bay {Link missing from include list}
// America/Tortola {Link missing from include list}
// America/Virgin {Link missing from include list}
// Antarctica/DumontDUrville {Link missing from include list}
// Antarctica/McMurdo {Link missing from include list}
// Antarctica/South_Pole {Link missing from include list}
// Antarctica/Syowa {Link missing from include list}
// Antarctica/Vostok {Link missing from include list}
// Arctic/Longyearbyen {Link missing from include list}
// Asia/Aden {Link missing from include list}
// Asia/Ashkhabad {Link missing from include list}
// Asia/Bahrain {Link missing from include list}
// Asia/Brunei {Link missing from include list}
// Asia/Calcutta {Link missing from include list}
// Asia/Chongqing {Link missing from include list}
// Asia/Chungking {Link missing from include list}
// Asia/Dacca {Link missing from include list}
// Asia/Harbin {Link missing from include list}
// Asia/Istanbul {Link missing from include list}
// Asia/Kashgar {Link missing from include list}
// Asia/Katmandu {Link missing from include list}
// Asia/Kuala_Lumpur {Link missing from include list}
// Asia/Kuwait {Link missing from include list}
// Asia/Macao {Link missing from include list}
// Asia/Muscat {Link missing from include list}
// Asia/Phnom_Penh {Link missing from include list}
// Asia/Rangoon {Link missing from include list}
// Asia/Saigon {Link missing from include list}
// Asia/Tel_Aviv {Link missing from include list}
// Asia/Thimbu {Link missing from include list}
// Asia/Ujung_Pandang {Link missing from include list}
// Asia/Ulan_Bator {Link missing from include list}
// Asia/Vientiane {Link missing from include list}
// Atlantic/Faeroe {Link missing from include list}
// Atlantic/Jan_Mayen {Link missing from include list}
// Atlantic/Reykjavik {Link missing from include list}
// Atlantic/St_Helena {Link missing from include list}
// Australia/ACT {Link missing from include list}
// Australia/Canberra {Link missing from include list}
// Australia/Currie {Link missing from include list}
// Australia/LHI {Link missing from include list}
// Australia/NSW {Link missing from include list}
// Australia/North {Link missing from include list}
// Australia/Queensland {Link missing from include list}
// Australia/South {Link missing from include list}
// Australia/Tasmania {Link missing from include list}
// Australia/Victoria {Link missing from include list}
// Australia/West {Link missing from include list}
// Australia/Yancowinna {Link missing from include list}
// Brazil/Acre {Link missing from include list}
// Brazil/DeNoronha {Link missing from include list}
// Brazil/East {Link missing from include list}
// Brazil/West {Link missing from include list}
// Canada/Atlantic {Link missing from include list}
// Canada/Central {Link missing from include list}
// Canada/Eastern {Link missing from include list}
// Canada/Mountain {Link missing from include list}
// Canada/Newfoundland {Link missing from include list}
// Canada/Pacific {Link missing from include list}
// Canada/Saskatchewan {Link missing from include list}
// Canada/Yukon {Link missing from include list}
// Chile/Continental {Link missing from include list}
// Chile/EasterIsland {Link missing from include list}
// Cuba {Link missing from include list}
// Egypt {Link missing from include list}
// Eire {Link missing from include list}
// Etc/GMT+0 {Link missing from include list}
// Etc/GMT-0 {Link missing from include list}
// Etc/GMT0 {Link missing from include list}
// Etc/Greenwich {Link missing from include list}
// Etc/UCT {Link missing from include list}
// Etc/Universal {Link missing from include list}
// Etc/Zulu {Link missing from include list}
// Europe/Amsterdam {Link missing from include list}
// Europe/Belfast {Link missing from include list}
// Europe/Bratislava {Link missing from include list}
// Europe/Busingen {Link missing from include list}
// Europe/Copenhagen {Link missing from include list}
// Europe/Guernsey {Link missing from include list}
// Europe/Isle_of_Man {Link missing from include list}
// Europe/Jersey {Link missing from include list}
// Europe/Kiev {Link missing from include list}
// Europe/Ljubljana {Link missing from include list}
// Europe/Luxembourg {Link missing from include list}
// Europe/Mariehamn {Link missing from include list}
// Europe/Monaco {Link missing from include list}
// Europe/Nicosia {Link missing from include list}
// Europe/Oslo {Link missing from include list}
// Europe/Podgorica {Link missing from include list}
// Europe/San_Marino {Link missing from include list}
// Europe/Sarajevo {Link missing from include list}
// Europe/Skopje {Link missing from include list}
// Europe/Stockholm {Link missing from include list}
// Europe/Tiraspol {Link missing from include list}
// Europe/Uzhgorod {Link missing from include list}
// Europe/Vaduz {Link missing from include list}
// Europe/Vatican {Link missing from include list}
// Europe/Zagreb {Link missing from include list}
// Europe/Zaporozhye {Link missing from include list}
// GB {Link missing from include list}
// GB-Eire {Link missing from include list}
// GMT {Link missing from include list}
// GMT+0 {Link missing from include list}
// GMT-0 {Link missing from include list}
// GMT0 {Link missing from include list}
// Greenwich {Link missing from include list}
// Hongkong {Link missing from include list}
// Iceland {Link missing from include list}
// Indian/Antananarivo {Link missing from include list}
// Indian/Christmas {Link missing from include list}
// Indian/Cocos {Link missing from include list}
// Indian/Comoro {Link missing from include list}
// Indian/Kerguelen {Link missing from include list}
// Indian/Mahe {Link missing from include list}
// Indian/Mayotte {Link missing from include list}
// Indian/Reunion {Link missing from include list}
// Iran {Link missing from include list}
// Israel {Link missing from include list}
// Jamaica {Link missing from include list}
// Japan {Link missing from include list}
// Kwajalein {Link missing from include list}
// Libya {Link missing from include list}
// Mexico/BajaNorte {Link missing from include list}
// Mexico/BajaSur {Link missing from include list}
// Mexico/General {Link missing from include list}
// NZ {Link missing from include list}
// NZ-CHAT {Link missing from include list}
// Navajo {Link missing from include list}
// PRC {Link missing from include list}
// Pacific/Chuuk {Link missing from include list}
// Pacific/Enderbury {Link missing from include list}
// Pacific/Funafuti {Link missing from include list}
// Pacific/Johnston {Link missing from include list}
// Pacific/Majuro {Link missing from include list}
// Pacific/Midway {Link missing from include list}
// Pacific/Pohnpei {Link missing from include list}
// Pacific/Ponape {Link missing from include list}
// Pacific/Saipan {Link missing from include list}
// Pacific/Samoa {Link missing from include list}
// Pacific/Truk {Link missing from include list}
// Pacific/Wake {Link missing from include list}
// Pacific/Wallis {Link missing from include list}
// Pacific/Yap {Link missing from include list}
// Poland {Link missing from include list}
// Portugal {Link missing from include list}
// ROC {Link missing from include list}
// ROK {Link missing from include list}
// Singapore {Link missing from include list}
// Turkey {Link missing from include list}
// UCT {Link missing from include list}
// US/Alaska {Link missing from include list}
// US/Aleutian {Link missing from include list}
// US/Arizona {Link missing from include list}
// US/Central {Link missing from include list}
// US/East-Indiana {Link missing from include list}
// US/Eastern {Link missing from include list}
// US/Hawaii {Link missing from include list}
// US/Indiana-Starke {Link missing from include list}
// US/Michigan {Link missing from include list}
// US/Mountain {Link missing from include list}
// US/Samoa {Link missing from include list}
// UTC {Link missing from include list}
// Universal {Link missing from include list}
// W-SU {Link missing from include list}
// Zulu {Link missing from include list}


//---------------------------------------------------------------------------
// Notable links: 0
//---------------------------------------------------------------------------



}
}

#endif
