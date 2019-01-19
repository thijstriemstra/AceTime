# Copyright 2018 Brian T. Park
#
# MIT License
"""
Generate the internal versions of zone_infos.py and zone_policies.py directly
instead of creating files. These maps can be used for further processing.
"""

import logging
from extractor import ZoneEra
from extractor import ZoneRule
from transformer import short_name
from argenerator import normalize_name
from argenerator import normalize_raw

class InlineGenerator:
    """Generate Python zone infos and policies maps inlined (instead of files).
    """

    def __init__(self, zones_map, rules_map):
        self.zones_map = zones_map
        self.rules_map = rules_map

        self.zone_infos = {}
        self.zone_policies = {}

    def generate_maps(self):
        """Return the zone_infos and zone_policies maps which look identical
        to the zone_infos.py and zone_policies.py generated by PythonGenerator.
        """
        logging.info('Generating inlined zone_policies and zone_infos')
        self.generate_policies()
        self.generate_infos()
        return (self.zone_infos, self.zone_policies)

    def generate_policies(self):
        for name, rules in self.rules_map.items():
            policy_rules = []
            for rule in rules:
                policy_rules.append(ZoneRule({
                    'fromYear': rule.fromYear,
                    'toYear': rule.toYear,
                    'inMonth': rule.inMonth,
                    'onDayOfWeek': rule.onDayOfWeek,
                    'onDayOfMonth': rule.onDayOfMonth,
                    'atSeconds': rule.atSecondsTruncated,
                    'atTimeModifier': rule.atTimeModifier,
                    'deltaSeconds': rule.deltaSecondsTruncated,
                    'letter': rule.letter
                }))

            normalized_name = normalize_name(name)
            self.zone_policies[normalized_name] = {
                'name': name,
                'rules': policy_rules
            }

    def generate_infos(self):
        for name, eras in self.zones_map.items():
            zone_eras = []
            for era in eras:
                policy_name = era.rules
                if policy_name in ['-', ':']:
                    zone_policy = policy_name
                else:
                    policy_name = normalize_name(policy_name)
                    zone_policy = self.zone_policies[policy_name]

                rules_delta_seconds = era.rulesDeltaSecondsTruncated
                if not rules_delta_seconds: rules_delta_seconds = 0

                zone_eras.append(ZoneEra({
                  'offsetSeconds': era.offsetSecondsTruncated,
                  'zonePolicy': zone_policy,
                  'rulesDeltaSeconds': rules_delta_seconds,
                  'format': era.format,
                  'untilYear': era.untilYear,
                  'untilMonth': era.untilMonth,
                  'untilDay': era.untilDay,
                  'untilSeconds': era.untilSecondsTruncated,
                  'untilTimeModifier': era.untilTimeModifier,
                }))
            sname = normalize_name(short_name(name))
            self.zone_infos[sname] = {
                'name': name,
                'eras': zone_eras
            }

