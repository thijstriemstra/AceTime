# Copyright 2019 Brian T. Park
#
# MIT License

"""
Generate the Arduino validation data files (validation_data.h and
validation_data.cpp) files and the AUnit unit test file (validation_tests.cpp)
from the 'validation_data.json' file on the STDIN.
"""

import logging
import os
from typing import List, Dict, Tuple, Optional
from transformer.transformer import div_to_zero, normalize_name
from .data import TestItem, TestData, ValidationData


class ArduinoValidationGenerator:
    """Generate Arduino data files for BasicPythonTest and ExtendedPythonTest.

    The blacklist is a dict of {zonename -> blacklist_policy}, where the
    blacklist_policy can be one of the following:

        * "full": the DST offsets from the given library returns incorrect
          results so the DST offset should be ignored and not validated. This is
          implemented by passing ValidationScope::kNone into the assertValid()
          method.
        * "partial": the DST offset returned by the library for 'A' and 'B'
          transitions are correct, but the DST only transitions indicated by 'a'
          and'b' are incorrect and should be ignored. This is implemented by
          passing ValidationScope::kExternal into the assertValid() method.
        * "" or no entry: If the policy is given as "", or the zone name is
          completely missing from the dictionary, then all DST offsets are
          checked. This is implemented by passing ValidationScope::kAll into
          the assertValid() method.
    """

    def __init__(
        self,
        invocation: str,
        tz_version: str,
        scope: str,
        db_namespace: str,
        validation_data: ValidationData,
        blacklist: Dict[str, str],
    ):
        self.invocation = invocation
        self.tz_version = tz_version
        self.db_namespace = db_namespace
        self.validation_data = validation_data
        self.blacklist = blacklist

        self.test_data = validation_data['test_data']
        self.file_base = 'validation'
        self.include_header_namespace = 'VALIDATION'
        if scope == 'basic':
            self.test_class = 'BasicTransitionTest'
        else:
            self.test_class = 'ExtendedTransitionTest'
        self.validation_data_h_file_name = (self.file_base + '_data.h')
        self.validation_data_cpp_file_name = (self.file_base + '_data.cpp')
        self.validation_tests_file_name = (self.file_base + '_tests.cpp')

    def generate_files(self, output_dir: str) -> None:
        self._write_file(output_dir, self.validation_data_h_file_name,
                         self._generate_validation_data_h())
        self._write_file(output_dir, self.validation_data_cpp_file_name,
                         self._generate_validation_data_cpp())
        self._write_file(output_dir, self.validation_tests_file_name,
                         self._generate_tests_cpp())

    def _write_file(self, output_dir: str, filename: str, content: str) -> None:
        full_filename = os.path.join(output_dir, filename)
        with open(full_filename, 'w', encoding='utf-8') as output_file:
            print(content, end='', file=output_file)
        logging.info("Created %s", full_filename)

    def _generate_validation_data_h(self) -> str:
        validation_items = self._generate_validation_data_h_items(
            self.test_data)
        source = self.validation_data['source']
        version = self.validation_data['version']

        return f"""\
// This file was generated by the following script:
//
//   $ {self.invocation}
//
// TZ Database comes from:
//   * https://github.com/eggert/tz/releases/tag/{self.tz_version}
//
// Third party database comes from:
//    * {source} (version {version})
//
// DO NOT EDIT

#ifndef ACE_TIME_VALIDATION_TEST_{self.include_header_namespace}_DATA_H
#define ACE_TIME_VALIDATION_TEST_{self.include_header_namespace}_DATA_H

#include <ace_time/testing/ValidationDataType.h>

namespace ace_time {{
namespace {self.db_namespace} {{

// numZones: {len(self.test_data)}
{validation_items}

}}
}}

#endif
"""

    def _generate_validation_data_h_items(self, test_data: TestData) -> str:
        validation_items = ''
        for zone_name, test_items in sorted(test_data.items()):
            normalized_name = normalize_name(zone_name)
            validation_items += f"""\
extern const testing::ValidationData kValidationData{normalized_name};
"""

        return validation_items

    def _generate_validation_data_cpp(self) -> str:
        validation_items = self._generate_validation_data_cpp_items(
            self.test_data)
        source = self.validation_data['source']
        version = self.validation_data['version']

        return f"""\
// This file was generated by the following script:
//
//   $ {self.invocation}
//
// TZ Database comes from:
//   * https://github.com/eggert/tz/releases/tag/{self.tz_version}
//
// Third party database comes from:
//    * {source} (version {version})
//
// DO NOT EDIT

#include <ace_time/testing/ValidationDataType.h>
#include "{self.file_base}_data.h"

namespace ace_time {{
namespace {self.db_namespace} {{

{validation_items}

}}
}}
"""

    def _generate_validation_data_cpp_items(self, test_data: TestData) -> str:
        validation_items = ''
        for zone_name, test_items in sorted(test_data.items()):
            test_items_string = self._generate_validation_data_cpp_test_items(
                zone_name, test_items)
            normalized_name = normalize_name(zone_name)

            validation_item = f"""\
//---------------------------------------------------------------------------
// Zone name: {zone_name}
//---------------------------------------------------------------------------

static const testing::ValidationItem kValidationItems{normalized_name}[] = {{
  //     epoch,  utc,  dst,    y,  m,  d,  h,  m,  s,  abbrev, type
{test_items_string}
}};

const testing::ValidationData kValidationData{normalized_name} = {{
  {len(test_items)} /*numItems*/,
  kValidationItems{normalized_name} /*items*/,
}};

"""
            validation_items += validation_item
        return validation_items

    def _generate_validation_data_cpp_test_items(
        self,
        zone_name: str,
        test_items: List[TestItem],
    ) -> str:
        """Generate the C++ code snippet related to the List[TestItem].
        """
        s = ''
        for test_item in test_items:
            epoch_seconds = test_item['epoch']
            total_offset_minutes = div_to_zero(test_item['total_offset'], 60)
            delta_offset_minutes = div_to_zero(test_item['dst_offset'], 60)
            year = test_item['y']
            month = test_item['M']
            day = test_item['d']
            hour = test_item['h']
            minute = test_item['m']
            second = test_item['s']
            abbrev_value = test_item['abbrev']
            abbrev = f'"{abbrev_value}"' if abbrev_value else 'nullptr'
            type = test_item['type']

            test_item_code = f"""\
  {{ {epoch_seconds:10}, {total_offset_minutes:4}, {delta_offset_minutes:4}, \
{year:4}, {month:2}, {day:2}, {hour:2}, {minute:2}, {second:2}, {abbrev:>7}, \
'{type}' }},
"""
            s += test_item_code
        return s

    def _generate_tests_cpp(self) -> str:
        test_cases = self._generate_test_cases(self.test_data)
        source = self.validation_data['source']
        version = self.validation_data['version']

        return f"""\
// This file was generated by the following script:
//
//   $ {self.invocation}
//
// TZ Database comes from:
//   * https://github.com/eggert/tz/releases/tag/{self.tz_version}
//
// Third party database comes from:
//    * {source} (version {version})
//
// DO NOT EDIT

#include <AUnitVerbose.h>
#include <ace_time/testing/{self.test_class}.h>
#include "{self.file_base}_data.h"
#include "{self.db_namespace}/zone_infos.h"
#include "{self.db_namespace}/zone_policies.h"

using namespace ace_time::testing;
using namespace ace_time::{self.db_namespace};

// numZones: {len(self.test_data)}
{test_cases}
"""

    def _generate_test_cases(self, test_data: TestData) -> str:
        has_valid_abbrev = self.validation_data['has_valid_abbrev']
        has_valid_dst = self.validation_data['has_valid_dst']
        test_cases = ''
        for zone_name, _ in sorted(test_data.items()):
            normalized_name = normalize_name(zone_name)

            (
                dst_validation_scope,
                dst_validation_comment,
            ) = _get_validation_scope(
                has_valid_dst,
                self.blacklist.get(zone_name),
            )
            (
                abbrev_validation_scope,
                abbrev_validation_comment,
            ) = _get_validation_scope(
                has_valid_abbrev,
                self.blacklist.get(zone_name),
            )

            test_case = f"""\
testF({self.test_class}, {normalized_name}) {{
  assertValid(
     &kZone{normalized_name},
     &kValidationData{normalized_name},
     {dst_validation_scope} /*dstValidationScope{dst_validation_comment}*/,
     {abbrev_validation_scope} \
/*abbrevValidationScope{abbrev_validation_comment}*/);
}}
"""
            test_cases += test_case
        return test_cases


def _get_validation_scope(
    is_valid: bool,
    blacklist_policy: Optional[str],
) -> Tuple[str, str]:
    """Determine the validationScope for DST and abbreviations."""
    if not is_valid:
        return 'ValidationScope::kNone', ' INVALID'

    if not blacklist_policy:
        return 'ValidationScope::kAll', ''

    if blacklist_policy == 'partial':
        return 'ValidationScope::kExternal', ' BLACKLISTED'

    if blacklist_policy == 'full':
        return 'ValidationScope::kNone', ' BLACKLISTED'

    raise Exception(f"Unrecognized blacklist policy '{blacklist_policy}'")
