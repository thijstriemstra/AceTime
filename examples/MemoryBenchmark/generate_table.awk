#!/usr/bin/gawk -f
#
# Usage: generate_table.sh < ${board}.txt
#
# Takes the file generated by collect.sh and generates an ASCII
# table that can be inserted into the README.md.

BEGIN {
  NUM_FEATURES = 24
  labels[0] = "baseline"
  labels[1] = "LocalDateTime"
  labels[2] = "ZonedDateTime"
  labels[3] = "Manual ZoneManager"
  labels[4] = "Basic TimeZone (1 zone)"
  labels[5] = "Basic TimeZone (2 zones)"
  labels[6] = "BasicZoneManager (1 zone)"
  labels[7] = "BasicZoneManager (all zones)"
  labels[8] = "BasicZoneManager (all zones+links)"
  labels[9] = "Basic ZoneSorterByName [1]"
  labels[10] = "Basic ZoneSorterByOffsetAndName [1]"
  labels[11] = "Extended TimeZone (1 zone)"
  labels[12] = "Extended TimeZone (2 zones)"
  labels[13] = "ExtendedZoneManager (1 zone)"
  labels[14] = "ExtendedZoneManager (all zones)"
  labels[15] = "ExtendedZoneManager (all zones+links)"
  labels[16] = "Extended ZoneSorterByName [2]"
  labels[17] = "Extended ZoneSorterByOffsetAndName [2]"
  labels[18] = "Complete TimeZone (1 zone)"
  labels[19] = "Complete TimeZone (2 zones)"
  labels[20] = "CompleteZoneManager (1 zone)"
  labels[21] = "CompleteZoneManager (all zones)"
  labels[22] = "CompleteZoneManager (all zones+links)"
  labels[23] = "Complete ZoneSorterByName [3]"
  labels[24] = "Complete ZoneSorterByOffsetAndName [3]"
  record_index = 0
}
{
  u[record_index]["flash"] = $2
  u[record_index]["ram"] = $4
  record_index++
}
END {
  base_flash = u[0]["flash"]
  base_ram = u[0]["ram"]
  for (i = 0; i <= NUM_FEATURES; i++) {
    if (u[i]["flash"] == -1) {
      u[i]["d_flash"] = -1
      u[i]["d_ram"] = -1
    } else {
      u[i]["d_flash"] = u[i]["flash"] - base_flash
      u[i]["d_ram"] = u[i]["ram"] - base_ram
    }
  }

  # Subtract the ZoneManager to get the incremental footprint of ZoneSorter
  basic_zone_manager = 6
  basic_sorter_by_name = 9
  basic_sorter_by_offset_and_name = 10
  u[basic_sorter_by_name]["d_flash"] -= u[basic_zone_manager]["d_flash"]
  u[basic_sorter_by_name]["d_ram"] -= u[basic_zone_manager]["d_ram"]
  u[basic_sorter_by_offset_and_name]["d_flash"] -= u[basic_zone_manager]["d_flash"]
  u[basic_sorter_by_offset_and_name]["d_ram"] -= u[basic_zone_manager]["d_ram"]

  extended_zone_manager = 13
  extended_sorter_by_name = 16
  extended_sorter_by_offset_and_name = 17
  u[extended_sorter_by_name]["d_flash"] -= u[extended_zone_manager]["d_flash"]
  u[extended_sorter_by_name]["d_ram"] -= u[extended_zone_manager]["d_ram"]
  u[extended_sorter_by_offset_and_name]["d_flash"] -= u[extended_zone_manager]["d_flash"]
  u[extended_sorter_by_offset_and_name]["d_ram"] -= u[extended_zone_manager]["d_ram"]

  complete_zone_manager = 20
  complete_sorter_by_name = 23
  complete_sorter_by_offset_and_name = 24
  u[complete_sorter_by_name]["d_flash"] -= u[complete_zone_manager]["d_flash"]
  u[complete_sorter_by_name]["d_ram"] -= u[complete_zone_manager]["d_ram"]
  u[complete_sorter_by_offset_and_name]["d_flash"] -= u[complete_zone_manager]["d_flash"]
  u[complete_sorter_by_offset_and_name]["d_ram"] -= u[complete_zone_manager]["d_ram"]

  printf(\
    "+----------------------------------------------------------------------+\n")
  printf(\
    "| Functionality                          |  flash/  ram |        delta |\n")

  for (i = 0; i <= NUM_FEATURES; i++) {
    name = labels[i]
    if (name ~ /^baseline/ \
        || name ~ /^LocalDateTime/ \
        || name ~ /^Basic TimeZone \(1 zone\)/ \
        || name ~ /^Basic ZoneSorterByName/ \
        || name ~ /^Extended TimeZone \(1 zone\)/ \
        || name ~ /^Extended ZoneSorterByName/ \
        || name ~ /^Complete TimeZone \(1 zone\)/ \
        || name ~ /^Complete ZoneSorterByName/) {
      printf(\
    "|----------------------------------------+--------------+--------------|\n")
    }

    printf("| %-38s | %6d/%5d | %6d/%5d |\n",
        name, u[i]["flash"], u[i]["ram"], u[i]["d_flash"], u[i]["d_ram"])
  }
  printf(\
    "+---------------------------------------------------------------------+\n")
}
