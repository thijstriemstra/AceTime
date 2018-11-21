#!/usr/bin/env python3
#
# Copyright 2018 Brian T. Park
#
# MIT License.
"""
Cleanses and transforms the 'zones' and 'rules' data so that it can be used to
generate the code for the static instances ZoneInfo and ZonePolicy classes.
"""

import logging

class Transformer:

    def __init__(self, zones_map, rules_map):
        self.zones_map = zones_map
        self.rules_map = rules_map

    def get_data(self):
        """
        The returned 'rules_map' is a map of (name -> rules[]), where each
        element in rules is another map with the following fields:

            fromYear: (int) from year
            toYear: (int) to year, 2000 to 9999=max
            inMonth: (int) month index (1-12)
            onDayOfWeek: (int) 1=Monday, 7=Sunday, 0={exact dayOfMonth match}
            onDayOfMonth: (int) (1-31), 0={last dayOfWeek match}
            atHour: (string) hour at which to transition to and from DST
            atMinute: (int) atHour as minutes since 00:00
            atHourModifier: (char) 's', 'w', 'g', 'u', 'z'
            deltaMinutes: (int) offset minutes from Standard time
            letter: (char) 'D', 'S', '-'
            rawLine: (string) the original RULE line from the TZ file
            deltaCode: (int) offset code (15 min chunks) from Standard time
            shortName: (string) short name of the zone

        The returned 'zones_map' is a map of (name -> zones[]), where each
        element in zones is another map with the following fields:

            offsetMinutes: (int) offset from UTC/GMT in minutes
            rules: (string) name of the Rule in effect, '-', or minute offset
            format: (string) abbreviation with '%s' replaced with '%'
                    (e.g. P%sT -> P%T, E%ST -> E%T, GMT/BST, SAST)
            untilYear: (int) 2000-9999
            untilMonth: (int) 1-12 optional
            untilDay: (string) 1-31, 'lastSun', 'Sun>=3', etc
            untilTime: (string) optional
            rawLine: (string) original ZONE line in TZ file
            used: (boolean) indicates whether or not the rule is used by a zone
        """
        return (self.zones_map, self.rules_map)

    def transform(self):
        zones_map = self.zones_map
        rules_map = self.rules_map

        zones_map = self.remove_zone_entries_too_old(zones_map)
        zones_map = self.remove_zones_with_until_month(zones_map)
        zones_map = self.remove_zones_with_offset_as_rules(zones_map)
        zones_map = self.remove_zones_without_slash(zones_map)
        zones_map = self.create_zones_with_offset_code(zones_map)

        (zones_map, rules_map) = self.mark_rules_used_by_zones(
            zones_map, rules_map)
        rules_map = self.remove_unused_rules(rules_map)

        rules_map = self.remove_rules_long_dst_letter(rules_map)
        rules_map = self.remove_rules_invalid_at_hour(rules_map)
        rules_map = self.create_rules_with_delta_code(rules_map)

        zones_map = self.remove_zones_without_rules(zones_map, rules_map)

        self.rules_map = rules_map
        self.zones_map = zones_map

    @staticmethod
    def mark_rules_used_by_zones(zones_map, rules_map):
        """Mark all rules which are required by various zones. There are 2 ways
        that a rule can be used by a zone entry:
        1) The rule's fromYear and toYear are >= 2000, or
        2) The rule is the most recent transition that happened before year
        2000.
        """
        for name, zone_entries in zones_map.items():
            begin_year = 2000
            for zone_entry in zone_entries:
                rule_name = zone_entry['rules']
                if rule_name == '-' or rule_name.isdigit():
                    continue

                rule_entries = rules_map.get(rule_name)
                if not rule_entries:
                    # This shouldn't happen
                    print('Zone name %s: Missing rule' % name)
                    continue

                # Mark rules in the [begin_year, until_year) interval.
                until_year = zone_entry['untilYear']
                matching_rules = find_matching_rules(
                    rule_entries, begin_year, until_year)
                for rule in matching_rules:
                    rule['used'] = True

                # Check if there's a transition rule prior to the first year.
                prior_match = find_most_recent_prior_rule(
                        rule_entries, begin_year)
                if prior_match:
                    prior_match['used'] = True

                begin_year = until_year

        return (zones_map, rules_map)

    @staticmethod
    def remove_rules_long_dst_letter(rules_map):
        """Return a new map which filters out rules with long DST letter.
        """
        results = {}
        count = 0
        for name, rules in rules_map.items():
            valid = True
            for rule in rules:
                if len(rule['letter']) > 1:
                    valid = False
                    count += 1
                    break
            if valid:
                results[name] = rules
        logging.info('Removed %s rules with long DST letter' % count)
        return results

    @staticmethod
    def remove_rules_invalid_at_hour(rules_map):
        """Remove rules whose atHour occurs off hour.
        """
        results = {}
        count = 0
        for name, rules in rules_map.items():
            valid = True
            for rule in rules:
                if rule['atMinute'] % 60 != 0:
                    valid = False
                    count += 1
                    break
            if valid:
                results[name] = rules
        logging.info('Removed %s rules with non-integral atHour' % count)
        return results

    @staticmethod
    def remove_unused_rules(rules_map):
        results = {}
        count = 0
        for name, rules in rules_map.items():
            used_rules = []
            for rule in rules:
                if 'used' in rule:
                    used_rules.append(rule)
                else:
                    count += 1
            if used_rules:
                results[name] = used_rules
        logging.info('Removed %s unused rules' % count)
        return results

    @staticmethod
    def create_rules_with_delta_code(rules_map):
        for name, rules in rules_map.items():
            for rule in rules:
                delta_minutes = rule['deltaMinutes']
                if delta_minutes % 15 != 0:
                    logging.error(
                        "Rule %s: delta minutes not multiple of 15: %s"
                        % (name, delta_minutes))
                delta_code = int(delta_minutes / 15)
                rule['deltaCode'] = delta_code
        return rules_map

    @staticmethod
    def remove_zones_with_until_month(zones_map):
        """
        """
        results = {}
        count = 0
        for name, zones in zones_map.items():
            valid = True
            for zone in zones:
                if zone['untilMonth']:
                    valid = False
                    count += 1
                    break
            if valid:
                results[name] = zones
        logging.info("Removed %s zones with unsupported untilMonth" % count)
        return results

    @staticmethod
    def remove_zones_with_offset_as_rules(zones_map):
        results = {}
        count = 0
        for name, zones in zones_map.items():
            valid = True
            for zone in zones:
                rule_name = zone['rules']
                if rule_name.isdigit():
                    valid = False
                    count += 1
                    break
            if valid:
               results[name] = zones
        logging.info("Removed %s zones with offset in 'rules' field" % count)
        return results

    @staticmethod
    def remove_zones_without_slash(zones_map):
        results = {}
        count = 0
        for name, zones in zones_map.items():
            if name.rfind('/') >= 0:
               results[name] = zones
            else:
                count += 1
        logging.info("Removed %s zones without '/' in name" % count)
        return results

    @staticmethod
    def remove_zone_entries_too_old(zones_map):
        """Remove zone entries which are too old, i.e. before 2000.
        """
        results = {}
        count = 0
        for name, zones in zones_map.items():
            keep_zones = []
            for zone in zones:
                if zone['untilYear'] >= 2000:
                    keep_zones.append(zone)
                else:
                    count += 1
            if keep_zones:
                results[name] = keep_zones

        logging.info("Removed %s zones entries too old" % count)
        return results

    @staticmethod
    def create_zones_with_offset_code(zones_map):
        for name, zones in zones_map.items():
            for zone in zones:
                offset_minutes = zone['offsetMinutes']
                if offset_minutes % 15 != 0:
                    logging.error(
                        "Zone %s: offset minutes not multiple of 15: %s"
                        % (name, offset_minutes))
                offset_code = int(offset_minutes / 15)
                zone['offsetCode'] = offset_code
        return zones_map

    @staticmethod
    def remove_zones_without_rules(zones_map, rules_map):
        results = {}
        count = 0
        for name, zones in zones_map.items():
            valid = True
            for zone in zones:
                rule_name = zone['rules']
                if rule_name != '-' and rule_name not in rules_map:
                    valid = False
                    break

            if valid:
                results[name] = zones
            else:
                count += 1
        logging.info("Removed %s zones without rules" % count)
        return results

def short_name(name):
    index = name.rfind('/')
    if index >= 0:
        short_name = name[index + 1:]
    else:
        short_name = name
    return short_name


def find_matching_rules(rule_entries, from_year, until_year):
    """Return the entries in rule_entries which overlap with the interval
    [from_year, until_year) inclusive to exclusive.
    """
    rules = []
    for rule_entry in rule_entries:
        if rule_entry['fromYear'] <= until_year - 1 and \
                from_year <= rule_entry['toYear']:
            rules.append(rule_entry)
    return rules


def find_most_recent_prior_rule(rule_entries, year):
    """Find the most recent prior rule before the given year.
    """
    candidate = None
    for rule_entry in rule_entries:
        if rule_entry['toYear'] < year:
            if not candidate:
                candidate = rule_entry
                continue
            if rule_entry['toYear'] > candidate['toYear']:
                candidate = rule_entry
                continue
            if rule_entry['toYear'] == candidate['toYear'] and \
                    rule_entry['inMonth'] > candidate['inMonth']:
                candidate = rule_entry
    return candidate
