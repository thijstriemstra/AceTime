# Copyright 2018 Brian T. Park
#
# MIT License
"""
Generate the zone_info and zone_policies files for Arduino.
"""

import os
import logging
from typing import Dict
from typing import List
from typing import Optional
from typing import Tuple
from typing import cast
from data_types.at_types import ZoneRuleRaw
from data_types.at_types import ZoneEraRaw
from data_types.at_types import ZonesMap
from data_types.at_types import PoliciesMap
from data_types.at_types import LinksMap
from data_types.at_types import CommentsMap
from data_types.at_types import IndexedLetters
from data_types.at_types import LettersMap
from data_types.at_types import ZoneInfoDatabase
from data_types.at_types import BufSizeMap
from transformer.transformer import normalize_name
from transformer.transformer import normalize_raw


class ArduinoGenerator:
    """Generate zone_infos and zone_policies files for Arduino/C++.
    """
    ZONE_INFOS_H_FILE_NAME = 'zone_infos.h'
    ZONE_INFOS_CPP_FILE_NAME = 'zone_infos.cpp'
    ZONE_POLICIES_H_FILE_NAME = 'zone_policies.h'
    ZONE_POLICIES_CPP_FILE_NAME = 'zone_policies.cpp'
    ZONE_REGISTRY_H_FILE_NAME = 'zone_registry.h'
    ZONE_REGISTRY_CPP_FILE_NAME = 'zone_registry.cpp'

    def __init__(
        self,
        invocation: str,
        db_namespace: str,
        zidb: ZoneInfoDatabase,
    ):
        # If I add a backslash (\) at the end of each line (which is needed if I
        # want to copy and paste the shell command), the C++ compiler spews out
        # warnings about "multi-line comment [-Wcomment]".
        wrapped_invocation = '\n//     --'.join(invocation.split(' --'))
        wrapped_tzfiles = '\n//   '.join(zidb['tz_files'])

        # Determine zonedb C++ namespace
        scope = zidb['scope']
        if not db_namespace:
            if scope == 'basic':
                db_namespace = 'zonedb'
            elif scope == 'extended':
                db_namespace = 'zonedbx'
            else:
                raise Exception(
                    f"db_namespace cannot be determined for scope '{scope}'"
                )

        self.zone_policies_generator = ZonePoliciesGenerator(
            invocation=wrapped_invocation,
            tz_files=wrapped_tzfiles,
            tz_version=zidb['tz_version'],
            scope=zidb['scope'],
            db_namespace=db_namespace,
            zones_map=zidb['zones_map'],
            policies_map=zidb['policies_map'],
            removed_zones=zidb['removed_zones'],
            removed_policies=zidb['removed_policies'],
            notable_zones=zidb['notable_zones'],
            notable_policies=zidb['notable_policies'],
            letters_map=zidb['letters_map'],
        )
        self.zone_infos_generator = ZoneInfosGenerator(
            invocation=wrapped_invocation,
            tz_files=wrapped_tzfiles,
            tz_version=zidb['tz_version'],
            scope=zidb['scope'],
            db_namespace=db_namespace,
            start_year=zidb['start_year'],
            until_year=zidb['until_year'],
            zones_map=zidb['zones_map'],
            links_map=zidb['links_map'],
            policies_map=zidb['policies_map'],
            removed_zones=zidb['removed_zones'],
            removed_links=zidb['removed_links'],
            removed_policies=zidb['removed_policies'],
            notable_zones=zidb['notable_zones'],
            notable_links=zidb['notable_links'],
            notable_policies=zidb['notable_policies'],
            buf_sizes=zidb['buf_sizes'],
            zone_ids=zidb['zone_ids'],
        )
        self.zone_registry_generator = ZoneRegistryGenerator(
            invocation=wrapped_invocation,
            tz_files=wrapped_tzfiles,
            tz_version=zidb['tz_version'],
            scope=zidb['scope'],
            db_namespace=db_namespace,
            zones_map=zidb['zones_map'],
        )

    def generate_files(self, output_dir: str) -> None:
        # zone_policies.*
        self._write_file(output_dir, self.ZONE_POLICIES_H_FILE_NAME,
                         self.zone_policies_generator.generate_policies_h())
        self._write_file(output_dir, self.ZONE_POLICIES_CPP_FILE_NAME,
                         self.zone_policies_generator.generate_policies_cpp())

        # zone_infos.*
        self._write_file(output_dir, self.ZONE_INFOS_H_FILE_NAME,
                         self.zone_infos_generator.generate_infos_h())
        self._write_file(output_dir, self.ZONE_INFOS_CPP_FILE_NAME,
                         self.zone_infos_generator.generate_infos_cpp())

        # zone_registry.*
        self._write_file(output_dir, self.ZONE_REGISTRY_H_FILE_NAME,
                         self.zone_registry_generator.generate_registry_h())
        self._write_file(output_dir, self.ZONE_REGISTRY_CPP_FILE_NAME,
                         self.zone_registry_generator.generate_registry_cpp())

    def _write_file(self, output_dir: str, filename: str, content: str) -> None:
        full_filename = os.path.join(output_dir, filename)
        with open(full_filename, 'w', encoding='utf-8') as output_file:
            print(content, end='', file=output_file)
        logging.info("Created %s", full_filename)


class ZonePoliciesGenerator:

    ZONE_POLICIES_H_FILE = """\
// This file was generated by the following script:
//
//   $ {invocation}
//
// using the TZ Database files
//
//   {tz_files}
//
// from https://github.com/eggert/tz/releases/tag/{tz_version}
//
// DO NOT EDIT

#ifndef ACE_TIME_{dbHeaderNamespace}_ZONE_POLICIES_H
#define ACE_TIME_{dbHeaderNamespace}_ZONE_POLICIES_H

#include <ace_time/internal/ZonePolicy.h>

namespace ace_time {{
namespace {dbNamespace} {{

//---------------------------------------------------------------------------
// Supported zone policies: {numPolicies}
//
{policyItems}

//---------------------------------------------------------------------------
// Unsupported zone policies: {numRemovedPolicies}
//
{removedPolicyItems}

// Notable zone policies: {numNotablePolicies}
//
{notablePolicyItems}

}}
}}

#endif
"""

    ZONE_POLICIES_H_POLICY_ITEM = """\
extern const {scope}::ZonePolicy kPolicy{policyName};
"""

    ZONE_POLICIES_H_REMOVED_POLICY_ITEM = """\
// kPolicy{policyName} ({policyReason})
"""

    ZONE_POLICIES_H_NOTABLE_POLICY_ITEM = """\
// kPolicy{policyName} ({policyReason})
"""

    ZONE_POLICIES_CPP_FILE = """\
// This file was generated by the following script:
//
//   $ {invocation}
//
// using the TZ Database files
//
//   {tz_files}
//
// from https://github.com/eggert/tz/releases/tag/{tz_version}
//
// Policies: {numPolicies}
// Rules: {numRules}
// Memory (8-bit): {memory8}
// Memory (32-bit): {memory32}
//
// DO NOT EDIT

#include <ace_time/common/compat.h>
#include "zone_policies.h"

namespace ace_time {{
namespace {dbNamespace} {{

{policyItems}

}}
}}
"""

    ZONE_POLICIES_CPP_POLICY_ITEM = """\
//---------------------------------------------------------------------------
// Policy name: {policyName}
// Rules: {numRules}
// Memory (8-bit): {memory8}
// Memory (32-bit): {memory32}
//---------------------------------------------------------------------------

static const {scope}::ZoneRule kZoneRules{policyName}[] {progmem} = {{
{ruleItems}
}};

{letterArray}

const {scope}::ZonePolicy kPolicy{policyName} {progmem} = {{
  kZoneRules{policyName} /*rules*/,
  {letterArrayRef} /*letters*/,
  {numRules} /*numRules*/,
  {numLetters} /*numLetters*/,
}};

"""

    ZONE_POLICIES_LETTER_ARRAY = """\
static const char* const kLetters{policyName}[] {progmem} = {{
{letterItems}
}};
"""

    ZONE_POLICIES_CPP_RULE_ITEM = """\
  // {rawLine}
  {{
    {fromYearTiny} /*fromYearTiny*/,
    {toYearTiny} /*toYearTiny*/,
    {inMonth} /*inMonth*/,
    {onDayOfWeek} /*onDayOfWeek*/,
    {onDayOfMonth} /*onDayOfMonth*/,
    {atTimeCode} /*atTimeCode*/,
    {atTimeModifier} /*atTimeModifier ({atTimeModifierComment})*/,
    {deltaCode} /*deltaCode ({deltaCodeComment})*/,
    {letter} /*letter{letterComment}*/,
  }},
"""

    SIZEOF_ZONE_RULE_8 = 9
    SIZEOF_ZONE_RULE_32 = 12
    SIZEOF_ZONE_POLICY_8 = 6
    SIZEOF_ZONE_POLICY_32 = 12

    def __init__(
        self,
        invocation: str,
        tz_version: str,
        tz_files: str,
        scope: str,
        db_namespace: str,
        zones_map: ZonesMap,
        policies_map: PoliciesMap,
        removed_zones: CommentsMap,
        removed_policies: CommentsMap,
        notable_zones: CommentsMap,
        notable_policies: CommentsMap,
        letters_map: LettersMap,
    ):
        self.invocation = invocation
        self.tz_version = tz_version
        self.tz_files = tz_files
        self.scope = scope
        self.db_namespace = db_namespace
        self.zones_map = zones_map
        self.policies_map = policies_map
        self.removed_zones = removed_zones
        self.removed_policies = removed_policies
        self.notable_zones = notable_zones
        self.notable_policies = notable_policies
        self.letters_map = letters_map

        self.db_header_namespace = self.db_namespace.upper()

    def generate_policies_h(self) -> str:
        policy_items = ''
        for name, rules in sorted(self.policies_map.items()):
            policy_items += self.ZONE_POLICIES_H_POLICY_ITEM.format(
                policyName=normalize_name(name),
                scope=self.scope)

        removed_policy_items = ''
        for name, reasons in sorted(self.removed_policies.items()):
            removed_policy_items += \
                self.ZONE_POLICIES_H_REMOVED_POLICY_ITEM.format(
                    policyName=name,
                    policyReason=', '.join(reasons))

        notable_policy_items = ''
        for name, reasons in sorted(self.notable_policies.items()):
            notable_policy_items += \
                self.ZONE_POLICIES_H_NOTABLE_POLICY_ITEM.format(
                    policyName=name,
                    policyReason=', '.join(reasons))

        return self.ZONE_POLICIES_H_FILE.format(
            invocation=self.invocation,
            tz_files=self.tz_files,
            tz_version=self.tz_version,
            dbNamespace=self.db_namespace,
            dbHeaderNamespace=self.db_header_namespace,
            numPolicies=len(self.policies_map),
            policyItems=policy_items,
            numRemovedPolicies=len(self.removed_policies),
            removedPolicyItems=removed_policy_items,
            numNotablePolicies=len(self.notable_policies),
            notablePolicyItems=notable_policy_items)

    def generate_policies_cpp(self) -> str:
        policy_items = ''
        memory8 = 0
        memory32 = 32
        num_rules = 0
        for name, rules in sorted(self.policies_map.items()):
            indexed_letters: Optional[IndexedLetters] = \
                self.letters_map.get(name)
            num_rules += len(rules)
            policy_item, policy_memory8, policy_memory32 = \
                self._generate_policy_item(name, rules, indexed_letters)
            policy_items += policy_item
            memory8 += policy_memory8
            memory32 += policy_memory32

        num_policies = len(self.policies_map)

        return self.ZONE_POLICIES_CPP_FILE.format(
            invocation=self.invocation,
            tz_files=self.tz_files,
            tz_version=self.tz_version,
            dbNamespace=self.db_namespace,
            dbHeaderNamespace=self.db_header_namespace,
            numPolicies=num_policies,
            numRules=num_rules,
            memory8=memory8,
            memory32=memory32,
            policyItems=policy_items)

    def _generate_policy_item(
        self,
        name: str,
        rules: List[ZoneRuleRaw],
        indexed_letters: Optional[IndexedLetters],
    ) -> Tuple[str, int, int]:

        # Generate kZoneRules*[]
        rule_items = ''
        for rule in rules:
            at_time_code = rule['atTimeCode']
            at_time_modifier = rule['atTimeModifier']
            at_time_modifier_comment = _get_time_modifier_comment(
                time_seconds=rule['atSecondsTruncated'],
                suffix=rule['atTimeSuffix'],
            )
            delta_code = rule['deltaCodeEncoded']
            delta_code_comment = _get_rule_delta_code_comment(
                delta_seconds=rule['deltaSecondsTruncated'],
                scope=self.scope,
            )
            from_year_tiny = rule['fromYearTiny']
            to_year_tiny = rule['toYearTiny']

            # Single-character 'letter' values are represented as themselves
            # using the C++ 'char' type ('A'-'Z'). But some 'letter' fields hold
            # a multi-character string. We can encode these multi-character
            # strings as an index into an array of NUL-terminated strings.
            # ASCII codes less than 32 (space) are non-printable control
            # characters so they will not collide with the printable characters
            # 'A' - 'Z'. Therefore we can hold to up to 31 multi-character
            # strings per-zone. In practice, for a single zone, the maximum
            # number of multi-character strings that I've seen is 2.
            letter = rule['letter']
            if len(letter) == 1:
                letterComment = ''
                letter = f"'{letter}'"
            elif len(letter) > 1:
                letterComment = f' (index to "{letter}")'
                letter = str(rule['letterIndex'])
            else:
                raise Exception(
                    'len(%s) == 0; should not happen'
                    % rule['letter'])

            rule_items += self.ZONE_POLICIES_CPP_RULE_ITEM.format(
                rawLine=normalize_raw(rule['rawLine']),
                fromYearTiny=from_year_tiny,
                toYearTiny=to_year_tiny,
                inMonth=rule['inMonth'],
                onDayOfWeek=rule['onDayOfWeek'],
                onDayOfMonth=rule['onDayOfMonth'],
                atTimeCode=at_time_code,
                atTimeModifier=at_time_modifier,
                atTimeModifierComment=at_time_modifier_comment,
                deltaCode=delta_code,
                deltaCodeComment=delta_code_comment,
                letter=letter,
                letterComment=letterComment)

        # Generate kLetters*[]
        policy_name = normalize_name(name)
        num_letters = len(indexed_letters) if indexed_letters else 0
        memory_letters8 = 0
        memory_letters32 = 0
        if num_letters:
            letters = cast(IndexedLetters, indexed_letters)
            letter_array_ref = f'kLetters{policy_name}'
            letterItems = ''
            for name, index in letters.items():
                letterItems += f'  /*{index}*/ "{name}",\n'
                memory_letters8 += len(name) + 1 + 2  # NUL terminated
                memory_letters32 += len(name) + 1 + 4  # NUL terminated
            letter_array = self.ZONE_POLICIES_LETTER_ARRAY.format(
                policyName=policy_name,
                letterItems=letterItems,
                progmem='ACE_TIME_PROGMEM')
        else:
            letter_array_ref = 'nullptr'
            letter_array = ''

        # Calculate the memory consumed by structs and arrays
        num_rules = len(rules)
        memory8 = (
            1 * self.SIZEOF_ZONE_POLICY_8
            + num_rules * self.SIZEOF_ZONE_RULE_8
            + memory_letters8)
        memory32 = (
            1 * self.SIZEOF_ZONE_POLICY_32
            + num_rules * self.SIZEOF_ZONE_RULE_32
            + memory_letters32)

        policy_item = self.ZONE_POLICIES_CPP_POLICY_ITEM.format(
            scope=self.scope,
            policyName=policy_name,
            numRules=num_rules,
            memory8=memory8,
            memory32=memory32,
            ruleItems=rule_items,
            numLetters=num_letters,
            letterArrayRef=letter_array_ref,
            letterArray=letter_array,
            progmem='ACE_TIME_PROGMEM')

        return (policy_item, memory8, memory32)


class ZoneInfosGenerator:
    ZONE_INFOS_H_FILE = """\
// This file was generated by the following script:
//
//   $ {invocation}
//
// using the TZ Database files
//
//   {tz_files}
//
// from https://github.com/eggert/tz/releases/tag/{tz_version}
//
// DO NOT EDIT

#ifndef ACE_TIME_{dbHeaderNamespace}_ZONE_INFOS_H
#define ACE_TIME_{dbHeaderNamespace}_ZONE_INFOS_H

#include <ace_time/internal/ZoneInfo.h>

namespace ace_time {{
namespace {dbNamespace} {{

//---------------------------------------------------------------------------
// ZoneContext (should not be in PROGMEM)
//---------------------------------------------------------------------------

// Version of the TZ Database which generated these files.
extern const char kTzDatabaseVersion[];

// Metadata about the zonedb files.
extern const {scope}::ZoneContext kZoneContext;

//---------------------------------------------------------------------------
// Supported zones: {numInfos}
//---------------------------------------------------------------------------

{infoItems}

{infoZoneIds}

//---------------------------------------------------------------------------
// Supported links: {numLinks}
//---------------------------------------------------------------------------

{linkItems}

//---------------------------------------------------------------------------
// Unsupported zones: {numRemovedInfos}
//---------------------------------------------------------------------------

{removedInfoItems}

//---------------------------------------------------------------------------
// Notable zones: {numNotableInfos}
//---------------------------------------------------------------------------

{notableInfoItems}

//---------------------------------------------------------------------------
// Unsupported links: {numRemovedLinks}
//---------------------------------------------------------------------------

{removedLinkItems}

//---------------------------------------------------------------------------
// Notable links: {numNotableLinks}
//---------------------------------------------------------------------------

{notableLinkItems}

}}
}}

#endif
"""

    ZONE_INFOS_H_INFO_ITEM = """\
extern const {scope}::ZoneInfo kZone{zoneNormalizedName}; // {zoneFullName}
"""

    ZONE_INFOS_H_INFO_ZONE_ID = """\
const uint32_t kZoneId{zoneNormalizedName} = 0x{zoneId:08x}; // {zoneFullName}
"""

    ZONE_INFOS_H_REMOVED_INFO_ITEM = """\
// {zoneFullName} ({reason})
"""

    ZONE_INFOS_H_NOTABLE_INFO_ITEM = """\
// {zoneFullName} ({reason})
"""

    ZONE_INFOS_H_LINK_ITEM = """\
extern const {scope}::ZoneInfo& kZone{linkNormalizedName}; \
// {linkFullName} -> {zoneFullName}
"""

    ZONE_INFOS_H_REMOVED_LINK_ITEM = """\
// {linkFullName} ({reason})
"""

    ZONE_INFOS_H_NOTABLE_LINK_ITEM = """\
// {linkFullName} ({reason})
"""

    ZONE_INFOS_CPP_FILE = """\
// This file was generated by the following script:
//
//   $ {invocation}
//
// using the TZ Database files
//
//   {tz_files}
//
// from https://github.com/eggert/tz/releases/tag/{tz_version}
//
// Zones: {numInfos}
// Links: {numLinks}
// Strings (bytes): {stringLength}
// Memory (8-bit): {memory8}
// Memory (32-bit): {memory32}
//
// DO NOT EDIT

#include <ace_time/common/compat.h>
#include "zone_policies.h"
#include "zone_infos.h"

namespace ace_time {{
namespace {dbNamespace} {{

//---------------------------------------------------------------------------
// ZoneContext (should not be in PROGMEM)
//---------------------------------------------------------------------------

const char kTzDatabaseVersion[] = "{tz_version}";

const {scope}::ZoneContext kZoneContext = {{
  {startYear} /*startYear*/,
  {untilYear} /*untilYear*/,
  kTzDatabaseVersion /*tzVersion*/,
}};

//---------------------------------------------------------------------------
// Zones: {numInfos}
//---------------------------------------------------------------------------

{infoItems}

//---------------------------------------------------------------------------
// Links: {numLinks}
//---------------------------------------------------------------------------

{linkItems}
}}
}}
"""

    ZONE_INFOS_CPP_INFO_ITEM = """\
//---------------------------------------------------------------------------
// Zone name: {zoneFullName}
// Zone Eras: {numEras}
// Strings (bytes): {stringLength}
// Memory (8-bit): {memory8}
// Memory (32-bit): {memory32}
//---------------------------------------------------------------------------

static const {scope}::ZoneEra kZoneEra{zoneNormalizedName}[] {progmem} = {{
{eraItems}
}};

static const char kZoneName{zoneNormalizedName}[] {progmem} = "{zoneFullName}";

const {scope}::ZoneInfo kZone{zoneNormalizedName} {progmem} = {{
  kZoneName{zoneNormalizedName} /*name*/,
  0x{zoneId:08x} /*zoneId*/,
  &kZoneContext /*zoneContext*/,
  {transitionBufSize} /*transitionBufSize*/,
  {numEras} /*numEras*/,
  kZoneEra{zoneNormalizedName} /*eras*/,
}};

"""

    ZONE_INFOS_CPP_ERA_ITEM = """\
  // {rawLine}
  {{
    {zonePolicy} /*zonePolicy*/,
    "{format}" /*format*/,
    {offsetCode} /*offsetCode*/,
    {deltaCode} /*deltaCode ({deltaCodeComment})*/,
    {untilYearTiny} /*untilYearTiny*/,
    {untilMonth} /*untilMonth*/,
    {untilDay} /*untilDay*/,
    {untilTimeCode} /*untilTimeCode*/,
    {untilTimeModifier} /*untilTimeModifier ({untilTimeModifierComment})*/,
  }},
"""

    ZONE_INFOS_CPP_LINK_ITEM = """\
const {scope}::ZoneInfo& kZone{linkNormalizedName} = kZone{zoneNormalizedName};
"""

    SIZEOF_ZONE_ERA_8 = 11
    SIZEOF_ZONE_ERA_32 = 16
    SIZEOF_ZONE_INFO_8 = 12
    SIZEOF_ZONE_INFO_32 = 20

    def __init__(
        self,
        invocation: str,
        tz_version: str,
        tz_files: str,
        scope: str,
        db_namespace: str,
        start_year: int,
        until_year: int,
        zones_map: ZonesMap,
        links_map: LinksMap,
        policies_map: PoliciesMap,
        removed_zones: CommentsMap,
        removed_links: CommentsMap,
        removed_policies: CommentsMap,
        notable_zones: CommentsMap,
        notable_links: CommentsMap,
        notable_policies: CommentsMap,
        buf_sizes: BufSizeMap,
        zone_ids: Dict[str, int],
    ):
        self.invocation = invocation
        self.tz_version = tz_version
        self.tz_files = tz_files
        self.scope = scope
        self.db_namespace = db_namespace
        self.start_year = start_year
        self.until_year = until_year
        self.zones_map = zones_map
        self.links_map = links_map
        self.policies_map = policies_map
        self.removed_zones = removed_zones
        self.removed_links = removed_links
        self.removed_policies = removed_policies
        self.notable_zones = notable_zones
        self.notable_links = notable_links
        self.notable_policies = notable_policies
        self.buf_sizes = buf_sizes
        self.zone_ids = zone_ids

        self.db_header_namespace = self.db_namespace.upper()

    def generate_infos_h(self) -> str:
        info_items = ''
        info_zone_ids = ''
        for zone_name, eras in sorted(self.zones_map.items()):
            info_items += self.ZONE_INFOS_H_INFO_ITEM.format(
                scope=self.scope,
                zoneNormalizedName=normalize_name(zone_name),
                zoneFullName=zone_name,
            )
            info_zone_ids += self.ZONE_INFOS_H_INFO_ZONE_ID.format(
                scope=self.scope,
                zoneNormalizedName=normalize_name(zone_name),
                zoneFullName=zone_name,
                zoneId=self.zone_ids[zone_name],
            )

        removed_info_items = ''
        for zone_name, reasons in sorted(self.removed_zones.items()):
            removed_info_items += self.ZONE_INFOS_H_REMOVED_INFO_ITEM.format(
                zoneFullName=zone_name, reason=', '.join(reasons))

        notable_info_items = ''
        for zone_name, reasons in sorted(self.notable_zones.items()):
            notable_info_items += self.ZONE_INFOS_H_NOTABLE_INFO_ITEM.format(
                zoneFullName=zone_name, reason=', '.join(reasons))

        link_items = ''
        for link_name, zone_name in sorted(self.links_map.items()):
            link_items += self.ZONE_INFOS_H_LINK_ITEM.format(
                scope=self.scope,
                linkNormalizedName=normalize_name(link_name),
                linkFullName=link_name,
                zoneFullName=zone_name)

        removed_link_items = ''
        for link_name, reasons in sorted(self.removed_links.items()):
            removed_link_items += self.ZONE_INFOS_H_REMOVED_LINK_ITEM.format(
                linkFullName=link_name, reason=', '.join(reasons))

        notable_link_items = ''
        for link_name, reasons in sorted(self.notable_links.items()):
            notable_link_items += self.ZONE_INFOS_H_NOTABLE_LINK_ITEM.format(
                linkFullName=link_name, reason=', '.join(reasons))

        return self.ZONE_INFOS_H_FILE.format(
            invocation=self.invocation,
            tz_files=self.tz_files,
            tz_version=self.tz_version,
            scope=self.scope,
            dbNamespace=self.db_namespace,
            dbHeaderNamespace=self.db_header_namespace,
            numInfos=len(self.zones_map),
            infoItems=info_items,
            infoZoneIds=info_zone_ids,
            numLinks=len(self.links_map),
            linkItems=link_items,
            numRemovedInfos=len(self.removed_zones),
            removedInfoItems=removed_info_items,
            numNotableInfos=len(self.notable_zones),
            notableInfoItems=notable_info_items,
            numRemovedLinks=len(self.removed_links),
            removedLinkItems=removed_link_items,
            numNotableLinks=len(self.notable_links),
            notableLinkItems=notable_link_items)

    def generate_infos_cpp(self) -> str:
        string_length = 0

        # Generate the list of zone infos
        info_items = ''
        num_eras = 0
        for zone_name, eras in sorted(self.zones_map.items()):
            (info_item, info_string_length) = self._generate_info_item(
                zone_name, eras)
            info_items += info_item
            string_length += info_string_length
            num_eras += len(eras)

        # Generate links references.
        link_items = ''
        for link_name, zone_name in sorted(self.links_map.items()):
            eras = self.zones_map[zone_name]
            link_items += self._generate_link_item(link_name, zone_name)

        # Estimate size of entire zone info database.
        num_infos = len(self.zones_map)
        num_links = len(self.links_map)
        memory8 = (
            string_length
            + num_eras * self.SIZEOF_ZONE_ERA_8
            + num_infos * self.SIZEOF_ZONE_INFO_8)
        memory32 = (
            string_length
            + num_eras * self.SIZEOF_ZONE_ERA_32
            + num_infos * self.SIZEOF_ZONE_INFO_32)

        return self.ZONE_INFOS_CPP_FILE.format(
            invocation=self.invocation,
            tz_files=self.tz_files,
            tz_version=self.tz_version,
            scope=self.scope,
            startYear=self.start_year,
            untilYear=self.until_year,
            dbNamespace=self.db_namespace,
            dbHeaderNamespace=self.db_header_namespace,
            numInfos=num_infos,
            numLinks=num_links,
            numEras=num_eras,
            stringLength=string_length,
            memory8=memory8,
            memory32=memory32,
            infoItems=info_items,
            linkItems=link_items)

    def _generate_info_item(
        self,
        zone_name: str,
        eras: List[ZoneEraRaw],
    ) -> Tuple[str, int]:
        era_items = ''
        string_length = 0
        for era in eras:
            (era_item, length) = self._generate_era_item(zone_name, era)
            era_items += era_item
            string_length += length

        string_length += len(zone_name) + 1
        num_eras = len(eras)
        memory8 = (
            string_length
            + num_eras * self.SIZEOF_ZONE_ERA_8
            + 1 * self.SIZEOF_ZONE_INFO_8)
        memory32 = (
            string_length
            + num_eras * self.SIZEOF_ZONE_ERA_32
            + 1 * self.SIZEOF_ZONE_INFO_32)

        transition_buf_size = self.buf_sizes[zone_name]

        info_item = self.ZONE_INFOS_CPP_INFO_ITEM.format(
            scope=self.scope,
            zoneFullName=zone_name,
            zoneNormalizedName=normalize_name(zone_name),
            zoneId=self.zone_ids[zone_name],
            transitionBufSize=transition_buf_size,
            numEras=num_eras,
            stringLength=string_length,
            memory8=memory8,
            memory32=memory32,
            eraItems=era_items,
            progmem='ACE_TIME_PROGMEM')
        return (info_item, string_length)

    def _generate_era_item(
        self, zone_name: str, era: ZoneEraRaw
    ) -> Tuple[str, int]:
        rules_policy_name = era['rules']
        if rules_policy_name == '-' or rules_policy_name == ':':
            zone_policy = 'nullptr'
        else:
            zone_policy = f'&kPolicy{normalize_name(rules_policy_name)}'

        offset_code = era['offsetCode']
        delta_code = era['deltaCodeEncoded']
        delta_code_comment = _get_era_delta_code_comment(
            offset_seconds=era['offsetSecondsTruncated'],
            delta_seconds=era['rulesDeltaSecondsTruncated'],
            scope=self.scope,
        )
        until_year_tiny = era['untilYearTiny']
        until_month = era['untilMonth']
        until_day = era['untilDay']
        until_time_code = era['untilTimeCode']
        until_time_modifier = era['untilTimeModifier']
        until_time_modifier_comment = _get_time_modifier_comment(
            time_seconds=era['untilSecondsTruncated'],
            suffix=era['untilTimeSuffix'],
        )
        format_short = era['formatShort']
        string_length = len(format_short) + 1

        era_item = self.ZONE_INFOS_CPP_ERA_ITEM.format(
            rawLine=normalize_raw(era['rawLine']),
            offsetCode=offset_code,
            deltaCode=delta_code,
            deltaCodeComment=delta_code_comment,
            zonePolicy=zone_policy,
            format=format_short,
            untilYearTiny=until_year_tiny,
            untilMonth=until_month,
            untilDay=until_day,
            untilTimeCode=until_time_code,
            untilTimeModifier=until_time_modifier,
            untilTimeModifierComment=until_time_modifier_comment,
        )

        return (era_item, string_length)

    def _generate_link_item(self, link_name: str, zone_name: str) -> str:
        return self.ZONE_INFOS_CPP_LINK_ITEM.format(
            scope=self.scope,
            linkFullName=link_name,
            linkNormalizedName=normalize_name(link_name),
            zoneFullName=zone_name,
            zoneNormalizedName=normalize_name(zone_name))


class ZoneRegistryGenerator:

    ZONE_REGISTRY_CPP_FILE = """\
// This file was generated by the following script:
//
//   $ {invocation}
//
// using the TZ Database files
//
//   {tz_files}
//
// from https://github.com/eggert/tz/releases/tag/{tz_version}
//
// DO NOT EDIT

#include <ace_time/common/compat.h>
#include "zone_infos.h"
#include "zone_registry.h"

namespace ace_time {{
namespace {dbNamespace} {{

//---------------------------------------------------------------------------
// Zone registry. Sorted by zone name.
//---------------------------------------------------------------------------
const {scope}::ZoneInfo* const kZoneRegistry[{numZones}] {progmem} = {{
{zoneRegistryItems}
}};

}}
}}
"""

    ZONE_REGISTRY_H_FILE = """\
// This file was generated by the following script:
//
//   $ {invocation}
//
// using the TZ Database files
//
//   {tz_files}
//
// from https://github.com/eggert/tz/releases/tag/{tz_version}
//
// DO NOT EDIT

#ifndef ACE_TIME_{dbHeaderNamespace}_ZONE_REGISTRY_H
#define ACE_TIME_{dbHeaderNamespace}_ZONE_REGISTRY_H

#include <ace_time/internal/ZoneInfo.h>

namespace ace_time {{
namespace {dbNamespace} {{

const uint16_t kZoneRegistrySize = {numZones};

extern const {scope}::ZoneInfo* const kZoneRegistry[{numZones}];

}}
}}
#endif
"""

    def __init__(
        self,
        invocation: str,
        tz_version: str,
        tz_files: str,
        scope: str,
        db_namespace: str,
        zones_map: ZonesMap,
    ):
        self.invocation = invocation
        self.tz_version = tz_version
        self.tz_files = tz_files
        self.scope = scope
        self.db_namespace = db_namespace
        self.zones_map = zones_map

        self.db_header_namespace = self.db_namespace.upper()

    def generate_registry_cpp(self) -> str:
        zone_registry_items = ''
        for zone_name, eras in sorted(self.zones_map.items()):
            name = normalize_name(zone_name)
            zone_registry_items += f'  &kZone{name}, // {zone_name}\n'
        return self.ZONE_REGISTRY_CPP_FILE.format(
            invocation=self.invocation,
            tz_files=self.tz_files,
            tz_version=self.tz_version,
            scope=self.scope,
            dbNamespace=self.db_namespace,
            dbHeaderNamespace=self.db_header_namespace,
            numZones=len(self.zones_map),
            zoneRegistryItems=zone_registry_items,
            progmem='ACE_TIME_PROGMEM')

    def generate_registry_h(self) -> str:
        return self.ZONE_REGISTRY_H_FILE.format(
            invocation=self.invocation,
            tz_files=self.tz_files,
            tz_version=self.tz_version,
            scope=self.scope,
            dbNamespace=self.db_namespace,
            dbHeaderNamespace=self.db_header_namespace,
            numZones=len(self.zones_map))


def _get_time_modifier_comment(
    time_seconds: int,
    suffix: str,
) -> str:
    """Create the comment that explains how the untilTimeCode or atTimeCode was
    calculated.
    """
    if suffix == 'w':
        comment = 'kSuffixW'
    elif suffix == 's':
        comment = 'kSuffixS'
    else:
        comment = 'kSuffixU'
    remaining_time_minutes = time_seconds % 900 // 60
    comment += f' + minute={remaining_time_minutes}'
    return comment


def _get_era_delta_code_comment(
    offset_seconds: int,
    delta_seconds: int,
    scope: str,
) -> str:
    """Create the comment that explains how the ZoneEra deltaCode[Encoded] was
    calculated.
    """
    offset_minute = offset_seconds % 900 // 60
    delta_minute = delta_seconds // 60
    if scope == 'extended':
        return (
            f"(offsetMinute={offset_minute} << 4) + "
            f"(deltaMinute={delta_minute}/15 + 4)"
        )
    else:
        return f"deltaMinute={delta_minute}/15"


def _get_rule_delta_code_comment(
    delta_seconds: int,
    scope: str,
) -> str:
    """Create the comment that explains how the ZoneRule deltaCode[Encoded] was
    calculated.
    """
    delta_minute = delta_seconds // 60
    if scope == 'extended':
        return f"deltaMinute={delta_minute}/15 + 4"
    else:
        return f"deltaMinute={delta_minute}/15"
