#!/usr/bin/env python3
#
# Copyright 2018 Brian T. Park
#
# MIT License
"""
Validate the inlined zonedb maps (zone_infos and zone_policies) generated by
InlineGenerator. These should be identical to the ZONE_INFO_MAP and
ZONE_POLICY_MAP created by PythonGenerator in the zone_infos.py and
zone_policies.py files.
"""

import logging
import datetime
import pytz
from transformer import seconds_to_hms
from zone_agent import ZoneAgent
from zone_agent import date_tuple_to_string
from zone_agent import to_utc_string
from zone_agent import print_matches_and_transitions
from zone_agent import SECONDS_SINCE_UNIX_EPOCH

class Validator:

    def __init__(self, zone_infos, zone_policies, optimized):
        self.zone_infos = zone_infos
        self.zone_policies = zone_policies
        self.optimized = optimized

    def validate_transition_buffer_size(self):
        """Determine the size of transition buffer required for each zone.
        """
        # map of {zoneName -> (numTransitions, year)}
        transition_stats = {}

        # Calculate the number of Transitions necessary for every Zone
        # in zone_infos, for the years 2000 to 2038.
        logging.info('Calculating transitions between 2000 and 2038')
        for zone_short_name, zone_info in self.zone_infos.items():
            zone_agent = ZoneAgent(zone_info, self.optimized)
            count_record = (0, 0) # (count, year)
            for year in range(2000, 2038):
                (matches, transitions) = \
                    zone_agent.get_matches_and_transitions(year)
                count = len(transitions)
                if count > count_record[0]:
                    count_record = (count, year)
            transition_stats[zone_short_name] = count_record

        logging.info('Count(transitions) group by zone order by count desc')
        for zone_short_name, count_record in sorted(
            transition_stats.items(), key=lambda x: x[1], reverse=True):
            logging.info('%s: %d (%04d)' % ((zone_short_name,) + count_record))

    def validate_dst_transitions(self):
        """Check the DST transitions for all zones, for the years 2000-2038,
        against the internal Python datetime implementation.
        """
        logging.info('Checking DST transitions against Python')
        for zone_short_name, zone_info in sorted(self.zone_infos.items()):
            logging.info('  Checking %s', zone_short_name)
            zone_agent = ZoneAgent(zone_info, self.optimized)
            zone_full_name = zone_info['name']
            try:
                tz = pytz.timezone(zone_full_name)
            except:
                logging.error("Zone '%s' not found in Python pytz package",
                    zone_full_name)
                continue

            for year in range(2000, 2038):
                (matches, transitions) = zone_agent.get_matches_and_transitions(
                    year)
                result = True
                for transition in transitions:
                    start = transition['startDateTime']
                    transition_year = start[0]
                    if transition_year != year: continue

                    epoch_seconds = transition['startEpochSecond']
                    result &= is_acetime_python_equal(
                        zone_full_name, zone_agent, start,
                        '+0s', epoch_seconds, tz)
                    result &= is_acetime_python_equal(
                        zone_full_name, zone_agent, start,
                        '-1s', epoch_seconds-1, tz)
                if not result:
                    print_matches_and_transitions(matches, transitions)


def is_acetime_python_equal(zone_name, zone_agent, start, label,
    epoch_seconds, tz):
    """Returns True or False whether AceTime and Python match.
    """
    # AceTime version
    (offset_seconds, dst_seconds, abbrev) = \
        zone_agent.get_timezone_info_from_seconds(epoch_seconds)
    utc_offset_seconds = offset_seconds + dst_seconds

    # Python version. See https://stackoverflow.com/questions/6410971
    # regarding the trickiness regarding Python datetime and pytz.
    unix_seconds = epoch_seconds + SECONDS_SINCE_UNIX_EPOCH
    utc_dt = datetime.datetime.fromtimestamp(
        unix_seconds, tz=datetime.timezone.utc)
    py_dt = utc_dt.astimezone(tz)
    py_utcoffset = int(py_dt.utcoffset().total_seconds())
    py_dst = int(py_dt.dst().total_seconds())

    if utc_offset_seconds != py_utcoffset:
        logging.error( "%s: offset mismatch; start: '%s'%s; "
            + "python: %s; unix: %s; "
            + "AceTime(%s); Python(%s)",
            zone_name,
            date_tuple_to_string(start),
            label,
            py_dt,
            unix_seconds,
            to_utc_string(offset_seconds, dst_seconds),
            to_utc_string(py_utcoffset-py_dst, py_dst))
        return False
    if dst_seconds != py_dst:
        logging.error( "%s: dst mismatch; start: '%s'%s; "
            + "python: %s; unix: %s; "
            + "AceTime(%s); Python(%s)",
            zone_name,
            date_tuple_to_string(start),
            label,
            py_dt,
            unix_seconds,
            to_utc_string(offset_seconds, dst_seconds),
            to_utc_string(py_utcoffset-py_dst, py_dst))
        return False
    return True
