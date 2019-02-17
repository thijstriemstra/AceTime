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
import collections
import pytz
from argenerator import normalize_name
from transformer import days_in_month
from transformer import seconds_to_hms
from transformer import short_name
from zone_specifier import ZoneSpecifier
from zone_specifier import date_tuple_to_string
from zone_specifier import to_utc_string
from zone_specifier import SECONDS_SINCE_UNIX_EPOCH
from zone_specifier import DateTuple
from zone_specifier import YearMonthTuple

# An entry in the test data set.
TestItem = collections.namedtuple(
    "TestItem", "epoch utc_offset dst_offset y M d h m s type")


class Validator:
    """Validate the zone_infos and zone_policies data from the TZ Database,
    as extracted and transformed by Extractor and Transformer.

    Usage:
        # For validation against pytz golden test data
        validator = Validator(zone_infos, zone_policies, ...)
        validator.validate_transition_buffer_size()
        validator.validate_sequentially()

        # For generating C++ unittest code
        validator = Validator(zone_infos, zone_policies, ...)
        (test_data, num_items) = validator.create_test_data()
        test_data_generator = TestDataGenerator(...)
        test_data_generator.generate_files(args.output_dir)
    """

    def __init__(self, zone_infos, zone_policies, viewing_months,
                 validate_dst_offset, validate_hours, debug_validator,
                 debug_specifier, zone_name, in_place_transitions):
        """
        Args:
            zone_infos: (dict) of {name -> zone_info{} }
            zone_policies: (dict) of {name ->zone_policy{} }
            viewing_months: (int) number of months in the calculation window
                (13, 14, 36)
            validate_dst_offset: (bool) validate DST offset against Python in
                addition to total UTC offset
            validate_hours: (bool) validate all 24 hours of a day, instead of a
                single selected sample hour
            debug_validator: (bool) enable debugging output for Validator
            debug_specifier: (bool) enable debugging output for ZoneSpecifier
            zone_name: (str) validate only this zone
            in_place_transitions: (bool)
        """
        self.zone_infos = zone_infos
        self.zone_policies = zone_policies
        self.viewing_months = viewing_months
        self.validate_dst_offset = validate_dst_offset
        self.validate_hours = validate_hours
        self.debug_validator = debug_validator
        self.debug_specifier = debug_specifier
        self.zone_name = zone_name
        self.in_place_transitions = in_place_transitions

    def validate_transition_buffer_size(self):
        """Determine the size of transition buffer required for each zone.
        """
        # map of {zoneName -> (numTransitions, year)}
        transition_stats = {}

        # Calculate the number of Transitions necessary for every Zone
        # in zone_infos, for the years 2000 to 2038.
        logging.info('Calculating transitions between 2000 and 2038')
        for zone_short_name, zone_info in sorted(self.zone_infos.items()):
            if self.zone_name != '' and zone_short_name != self.zone_name:
                continue
            if self.debug_validator:
                logging.info('Validating zone %s' % zone_short_name)

            zone_specifier = ZoneSpecifier(zone_info, self.viewing_months,
                self.debug_specifier, self.in_place_transitions)
            # pair of tuple(count, year), transition count, and candidate count
            count_record = ((0, 0), (0, 0))
            for year in range(2000, 2038):
                #logging.info('Validating year %s' % year)
                zone_specifier.init_for_year(year)
                transition_count = len(zone_specifier.transitions)
                candidate_count = len(zone_specifier.candidate_transitions)
                if transition_count > count_record[0][0]:
                    count_record = ((transition_count, year), count_record[1])
                if candidate_count > count_record[1][0]:
                    count_record = (count_record[0], (candidate_count, year))
            transition_stats[zone_short_name] = count_record

        logging.info('Count(transitions) group by zone order by count desc')
        for zone_short_name, count_record in sorted(
                transition_stats.items(), key=lambda x: x[1], reverse=True):
            logging.info('%s: %d (%04d); %d (%04d)' %
                 ((zone_short_name, ) + count_record[0] + count_record[1]))

    def validate_sequentially(self):
        """Compare Python and AceTime offsets by generating the Python
        test data first. This allows the test data to be exported, for example,
        as a C++ test data set.
        """
        logging.info('Creating test data')
        (test_data, num_items) = self.create_test_data()

        logging.info('Validating %s test items', num_items)
        self.validate_test_data(test_data)

    def validate_test_data(self, test_data):
        for zone_short_name, items in test_data.items():
            if self.debug_validator:
                logging.info('  Validating zone %s' % zone_short_name)
            if self.validate_hours:
                # Debugging output when generating 'hours' takes a long time
                logging.info('  Validating test data for %s', zone_short_name)
            self.validate_test_data_for_zone(zone_short_name, items)

    def validate_test_data_for_zone(self, zone_short_name, items):
        zone_info = self.zone_infos[zone_short_name]
        zone_specifier = ZoneSpecifier(zone_info, self.viewing_months,
            self.debug_specifier, self.in_place_transitions)
        for item in items:
            if self.debug_validator:
                logging.info('    %04d-%02d-%02d %02d:%02d epoch:%d' %
                    (item.y, item.M, item.d, item.h, item.m, item.epoch))
            try:
                (offset_seconds, dst_seconds, abbrev) = \
                    zone_specifier.get_timezone_info_for_seconds(item.epoch)
                unix_seconds = item.epoch + SECONDS_SINCE_UNIX_EPOCH
                utc_offset_seconds = offset_seconds + dst_seconds
            except Exception:
                logging.exception('Exception with test data %s', item)
                raise

            if utc_offset_seconds != item.utc_offset:
                logging.error(
                    "==== %s: offset mismatch; at: '%s'; unix: %s; " +
                    "AceTime(%s); Expected(%s)", zone_short_name,
                    test_item_to_string(item), unix_seconds,
                    to_utc_string(offset_seconds, dst_seconds),
                    to_utc_string(item.utc_offset - item.dst_offset,
                                  item.dst_offset))
                zone_specifier.init_for_year(item.y)
                zone_specifier.print_matches_and_transitions()

    def create_test_data(self):
        """Create a map of {
            zone_short_name: [ TestItem() ]
        }
        Return (test_data, num_items).
        """
        test_data = {}
        num_items = 0
        for zone_short_name, zone_info in sorted(self.zone_infos.items()):
            if self.zone_name != '' and zone_short_name != self.zone_name:
                continue
            test_items = self.create_test_data_for_zone(
                zone_short_name, zone_info)
            if test_items:
                test_data[zone_short_name] = test_items
                num_items += len(test_items)
        return (test_data, num_items)

    def create_test_data_for_zone(self, zone_short_name, zone_info):
        """Create the TestItems for a specific zone.
        """
        zone_specifier = ZoneSpecifier(zone_info, self.viewing_months,
            self.debug_specifier, self.in_place_transitions)
        zone_full_name = zone_info['name']
        try:
            tz = pytz.timezone(zone_full_name)
        except:
            logging.error("Zone '%s' not found in Python pytz package",
                          zone_full_name)
            return None

        if self.validate_hours:
            # Debugging output when generating 'hours' takes a long time
            logging.info('  Creating test data for %s', zone_short_name)
        test_items = self.create_transition_test_items(tz, zone_specifier)
        if self.validate_hours:
            test_items.extend(self.create_hourly_test_items(tz, zone_specifier))
        return test_items

    def create_transition_test_items(self, tz, zone_specifier):
        """Create a TestItem for the tz for each Transition instance found by
        the ZoneSpecifier, for each year from 2000 to 2019.

        If the ZoneSpecifier is created with viewing_months=13, the first
        Transition occurs at the year boundary. The ZoneSpecifier has no prior
        Transition for 'epoch_seconds - 1', so a call to ZoneSpecifier for
        this will probably fail.

        If the ZoneSpecifier is created with viewing_months=14, then a
        Transition is created for Dec 1 of the prior year, so all of the test
        data points below will probably work.

        Some zones do not use DST, so will have no test samples here.
        """
        items = []
        for year in range(2000, 2019):
            # Skip year 2000 when viewing months is 36, because it needs
            # data for 1997, and we don't generate those. Only 1998.
            if self.viewing_months == 36 and year == 2000: continue

            # Check the transition at the beginning of year.
            test_item = self.create_test_item_from_datetime(
                tz, year, month=1, day=1, hour=0, type='Y')
            items.append(test_item)

            # Check the transition at the end of the year.
            test_item = self.create_test_item_from_datetime(
                tz, year, month=12, day=31, hour=23, type='Y')
            items.append(test_item)

            # Add the before and after samples surrounding a DST transition.
            zone_specifier.init_for_year(year)
            transition_found = False
            for transition in zone_specifier.transitions:
                # Some Transitions from ZoneSpecifier are in previous or post
                # years (e.g. viewing_months = [14, 36]), so skip those.
                start = transition.startDateTime
                transition_year = start.y
                if transition_year != year: continue

                # If viewing_months== (13 or 36), don't look at Transitions at
                # the beginning of the year since those have been already added.
                if self.viewing_months in [13, 36]:
                    if start.M == 1 and start.d == 1 and start.ss == 0:
                        continue

                epoch_seconds = transition.startEpochSecond
                items.append(
                    self.create_test_item_from_epoch_seconds(
                        tz, epoch_seconds - 1, 'A'))
                items.append(
                    self.create_test_item_from_epoch_seconds(
                        tz, epoch_seconds, 'B'))
                transition_found = True

            # If no transition found within the year, add a test sample
            # so that there's at least one sample per year.
            if not transition_found:
                items.append(
                    self.create_test_item_from_datetime(
                        tz, year, month=3, day=10, hour=2, type='S'))

        return items

    def create_hourly_test_items(self, tz, zone_specifier):
        items = []
        for year in range(2000, 2018):
            for month in range(1, 13):
                days = days_in_month(year, month)
                for day in range(1, days + 1):
                    if self.validate_hours:
                        for hour in range(0, 24):
                            test_item = self.create_test_item_from_datetime(
                                tz, year, month, day, hour, 'S')
                    else:
                        hour = month - 1  # try different hours
                        test_item = self.create_test_item_from_datetime(
                            tz, year, month, day, hour, 'S')
                    items.append(test_item)
        return items

    def create_test_item_from_datetime(self, tz, year, month, day, hour, type):
        """Create a TestItem for the given year, month, day, hour in local
        time zone.
        """
        # Can't use the normal datetime constructor for pytz. Must use
        # timezone.localize(). See https://stackoverflow.com/questions/18541051
        dt = tz.localize(datetime.datetime(year, month, day, hour))
        unix_seconds = int(dt.timestamp())
        epoch_seconds = unix_seconds - SECONDS_SINCE_UNIX_EPOCH
        return self.create_test_item_from_epoch_seconds(
            tz, epoch_seconds, type)

    def create_test_item_from_epoch_seconds(self, tz, epoch_seconds, type):
        """Return the TestItem fro the epoch_seconds.
            utc_offset: the total UTC offset
            dst_offset: the DST offset
        The base offset is (utc_offset - dst_offset).
        """
        unix_seconds = epoch_seconds + SECONDS_SINCE_UNIX_EPOCH
        utc_dt = datetime.datetime.fromtimestamp(
            unix_seconds, tz=datetime.timezone.utc)
        dt = utc_dt.astimezone(tz)
        utc_offset = int(dt.utcoffset().total_seconds())
        dst_offset = int(dt.dst().total_seconds())

        return TestItem(
            epoch=epoch_seconds,
            utc_offset=utc_offset,
            dst_offset=dst_offset,
            y=dt.year,
            M=dt.month,
            d=dt.day,
            h=dt.hour,
            m=dt.minute,
            s=dt.second,
            type=type)


def test_item_to_string(i):
    return '%04d-%02d-%02dT%02d:%02d:%02d' % (i.y, i.M, i.d, i.h, i.m, i.s)


# List of zones where the Python DST offset is incorrect.
TIME_ZONES_BLACKLIST = {
    'America/Argentina/Buenos_Aires',  # Python is wrong
    'America/Argentina/Cordoba',  # Python is wrong
    'America/Argentina/Jujuy',  # Python is wrong
    'America/Argentina/Salta',  # Python is wrong
    'America/Bahia_Banderas',  # Python is wrong
    'America/Indiana/Winamac',  # Python is wrong
}
