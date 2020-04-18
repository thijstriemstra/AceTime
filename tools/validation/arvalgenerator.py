# Copyright 2019 Brian T. Park
#
# MIT License

"""
Generate the Arduino validation data (validation_data.h and validation_data.cpp)
files for unit tests from the 'validation_data' (or its JSON representation).
"""

import logging
import os
import re
from validation.data import (TestItem, TestData, ValidationData)
from typing import List


# Copied from transformer.div_to_zero()
def div_to_zero(a: int, b: int) -> int:
    """Integer division (a/b) that truncates towards 0, instead of -infinity as
    is default for Python. Assumes b is positive, but a can be negative or
    positive.
    """
    return a // b if a >= 0 else ((a - 1) // b + 1)


# Copied from transformer.normalize_name()
def normalize_name(name: str) -> str:
    """Replace hyphen (-) and slash (/) with underscore (_) to generate valid
    C++ and Python symbols.
    """
    name = name.replace('+', '_PLUS_')
    return re.sub('[^a-zA-Z0-9_]', '_', name)


class ArduinoValidationGenerator:
    """Generate Arduino data files for BasicPythonTest and ExtendedPythonTest.
    """

    VALIDATION_DATA_H_FILE = """\
// This file was generated by the following script:
//
//  $ {invocation}
//
// TZ Database comes from:
//   * https://github.com/eggert/tz/releases/tag/{tz_version}
//
// Third party database comes from:
//    * {source} (version {version})
//
// DO NOT EDIT

#ifndef ACE_TIME_VALIDATION_TEST_{includeHeaderNamespace}_DATA_H
#define ACE_TIME_VALIDATION_TEST_{includeHeaderNamespace}_DATA_H

#include <ace_time/testing/ValidationDataType.h>

namespace ace_time {{
namespace {dbNamespace} {{

// numZones: {numZones}
{validationItems}

}}
}}

#endif
"""

    VALIDATION_DATA_H_ITEM = """\
extern const testing::ValidationData kValidationData{zoneNormalizedName};
"""

    VALIDATION_DATA_CPP_FILE = """\
// This file was generated by the following script:
//
//   $ {invocation}
//
// TZ Database comes from:
//   * https://github.com/eggert/tz/releases/tag/{tz_version}
//
// Third party database comes from:
//    * {source} (version {version})
//
// DO NOT EDIT

#include <ace_time/testing/ValidationDataType.h>
#include "{fileBase}_data.h"

namespace ace_time {{
namespace {dbNamespace} {{

{validationItems}

}}
}}
"""

    VALIDATION_DATA_CPP_ITEM = """\
//---------------------------------------------------------------------------
// Zone name: {zoneFullName}
//---------------------------------------------------------------------------

static const testing::ValidationItem kValidationItems{zoneNormalizedName}[] = {{
  //     epoch,  utc,  dst,    y,  m,  d,  h,  m,  s,  abbrev
{testItems}
}};

const testing::ValidationData kValidationData{zoneNormalizedName} = {{
  {numItems} /*numItems*/,
  kValidationItems{zoneNormalizedName} /*items*/,
}};

"""

    TEST_ITEM = """\
  {{ {epochSeconds:10}, {totalOffsetMinutes:4}, {deltaOffsetMinutes:4}, \
{year:4}, {month:2}, {day:2}, {hour:2}, {minute:2}, {second:2}, nullptr }}, \
// type={type}
"""

    VALIDATION_TESTS_CPP = """\
// This file was generated by the following script:
//
//   $ {invocation}
//
// TZ Database comes from:
//   * https://github.com/eggert/tz/releases/tag/{tz_version}
//
// Third party database comes from:
//    * {source} (version {version})
//
// DO NOT EDIT

#include <AUnit.h>
#include <ace_time/testing/{testClass}.h>
#include "{fileBase}_data.h"
#include "{dbNamespace}/zone_infos.h"
#include "{dbNamespace}/zone_policies.h"

using namespace ace_time::testing;
using namespace ace_time::{dbNamespace};

// numZones: {numZones}
{testCases}
"""

    VALIDATION_TEST_CASE = """\
testF({testClass}, {zoneNormalizedName}) {{
  assertValid(&kZone{zoneNormalizedName}, &kValidationData{zoneNormalizedName});
}}
"""

    def __init__(
        self,
        invocation: str,
        tz_version: str,
        scope: str,
        db_namespace: str,
        validation_data: ValidationData,
    ):
        self.invocation = invocation
        self.tz_version = tz_version
        self.db_namespace = db_namespace
        self.validation_data = validation_data

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

        return self.VALIDATION_DATA_H_FILE.format(
            invocation=self.invocation,
            tz_version=self.tz_version,
            source=self.validation_data['source'],
            version=self.validation_data['version'],
            includeHeaderNamespace=self.include_header_namespace,
            dbNamespace=self.db_namespace,
            numZones=len(self.test_data),
            validationItems=validation_items)

    def _generate_validation_data_h_items(self, test_data: TestData) -> str:
        validation_items = ''
        for zone_name, test_items in sorted(test_data.items()):
            validation_items += self.VALIDATION_DATA_H_ITEM.format(
                zoneNormalizedName=normalize_name(zone_name))
        return validation_items

    def _generate_validation_data_cpp(self) -> str:
        validation_items = self._generate_validation_data_cpp_items(
            self.test_data)

        return self.VALIDATION_DATA_CPP_FILE.format(
            invocation=self.invocation,
            tz_version=self.tz_version,
            source=self.validation_data['source'],
            version=self.validation_data['version'],
            fileBase=self.file_base,
            dbNamespace=self.db_namespace,
            validationItems=validation_items)

    def _generate_validation_data_cpp_items(self, test_data: TestData) -> str:
        validation_items = ''
        for zone_name, test_items in sorted(test_data.items()):
            test_items_string = self._generate_validation_data_cpp_test_items(
                zone_name, test_items)
            validation_item = self.VALIDATION_DATA_CPP_ITEM.format(
                zoneFullName=zone_name,
                zoneNormalizedName=normalize_name(zone_name),
                numItems=len(test_items),
                testItems=test_items_string)
            validation_items += validation_item
        return validation_items

    def _generate_validation_data_cpp_test_items(
        self,
        zone_name: str,
        test_items: List[TestItem],
    ) -> str:
        """Generate the {testItems} value.
        """
        s = ''
        for test_item in test_items:
            total_offset_minutes = div_to_zero(test_item['total_offset'], 60)
            delta_offset_minutes = div_to_zero(test_item['dst_offset'], 60)
            s += self.TEST_ITEM.format(
                epochSeconds=test_item['epoch'],
                totalOffsetMinutes=total_offset_minutes,
                deltaOffsetMinutes=delta_offset_minutes,
                year=test_item['y'],
                month=test_item['M'],
                day=test_item['d'],
                hour=test_item['h'],
                minute=test_item['m'],
                second=test_item['s'],
                type=test_item['type'])
        return s

    def _generate_tests_cpp(self) -> str:
        test_cases = self._generate_test_cases(self.test_data)

        return self.VALIDATION_TESTS_CPP.format(
            invocation=self.invocation,
            tz_version=self.tz_version,
            source=self.validation_data['source'],
            version=self.validation_data['version'],
            testClass=self.test_class,
            fileBase=self.file_base,
            numZones=len(self.test_data),
            testCases=test_cases,
            dbNamespace=self.db_namespace,
        )

    def _generate_test_cases(self, test_data: TestData) -> str:
        test_cases = ''
        for zone_name, _ in sorted(test_data.items()):
            test_case = self.VALIDATION_TEST_CASE.format(
                dbNamespace=self.db_namespace,
                testClass=self.test_class,
                zoneNormalizedName=normalize_name(zone_name))
            test_cases += test_case
        return test_cases
