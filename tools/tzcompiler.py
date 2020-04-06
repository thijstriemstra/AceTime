#!/usr/bin/env python3
#
# Copyright 2018 Brian T. Park
#
# MIT License.

import argparse
import logging
import sys
from typing import List
from typing_extensions import Protocol

from extractor import Extractor, ZonesMap, RulesMap, LinksMap
from transformer import Transformer, CommentsMap, StringCollection
from argenerator import ArduinoGenerator
from jsongenerator import JsonGenerator
from pygenerator import PythonGenerator
from ingenerator import InlineGenerator, ZoneInfoMap, ZonePolicyMap
from zonelistgenerator import ZoneListGenerator
from bufestimator import BufSizeEstimator


class Generator(Protocol):
    def generate_files(self, name: str) -> None:
        ...


def generate_zonedb(
    invocation: str,
    tz_version: str,
    tz_files: List[str],
    scope: str,
    db_namespace: str,
    zones_map: ZonesMap,
    links_map: LinksMap,
    rules_map: RulesMap,
    removed_zones: CommentsMap,
    removed_links: CommentsMap,
    removed_policies: CommentsMap,
    notable_zones: CommentsMap,
    notable_links: CommentsMap,
    notable_policies: CommentsMap,
    format_strings: StringCollection,
    zone_strings: StringCollection,
    zone_infos: ZoneInfoMap,
    zone_policies: ZonePolicyMap,
    language: str,
    start_year: int,
    until_year: int,
    output_dir: str,
    generate_zone_strings: bool,
) -> None:

    generator: Generator

    # Create the Python or Arduino files if requested
    if not output_dir:
        logging.error('Must provide --output_dir to generate zonedb files')
        sys.exit(1)
    if language == 'python':
        logging.info('======== Creating Python zonedb files')
        generator = PythonGenerator(
            invocation=invocation,
            tz_version=tz_version,
            tz_files=Extractor.ZONE_FILES,
            zones_map=zones_map,
            rules_map=rules_map,
            removed_zones=removed_zones,
            removed_policies=removed_policies,
            notable_zones=notable_zones,
            notable_policies=notable_policies)
        generator.generate_files(output_dir)
    elif language == 'arduino':
        logging.info('======== Creating Arduino zonedb files')

        # Determine zonedb C++ namespace
        # TODO: Maybe move this into ArduinoGenerator?
        if not db_namespace:
            if scope == 'basic':
                db_namespace = 'zonedb'
            elif scope == 'extended':
                db_namespace = 'zonedbx'
            else:
                raise Exception(
                    f"db_namespace cannot be determined for scope '{scope}'"
                )

        # Generate the buf_size estimates for each zone, between start_year and
        # until_year.
        logging.info('==== Estimating transition buffer sizes')
        logging.info('Checking years in [%d, %d)', start_year, until_year)
        estimator = BufSizeEstimator(
            zone_infos, zone_policies, start_year, until_year)
        (buf_sizes, max_size) = estimator.estimate()
        logging.info(
            'Num zones=%d; Max buffer size=%d',
            len(buf_sizes), max_size,
        )

        generator = ArduinoGenerator(
            invocation=invocation,
            tz_version=tz_version,
            tz_files=Extractor.ZONE_FILES,
            scope=scope,
            db_namespace=db_namespace,
            generate_zone_strings=generate_zone_strings,
            start_year=start_year,
            until_year=until_year,
            zones_map=zones_map,
            links_map=links_map,
            rules_map=rules_map,
            removed_zones=removed_zones,
            removed_links=removed_links,
            removed_policies=removed_policies,
            notable_zones=notable_zones,
            notable_links=notable_links,
            notable_policies=notable_policies,
            format_strings=format_strings,
            zone_strings=zone_strings,
            buf_sizes=buf_sizes)
        generator.generate_files(output_dir)
    elif language == 'json':
        logging.info('======== Creating JSON zonedb files')
        generator = JsonGenerator(
            tz_version=tz_version,
            tz_files=Extractor.ZONE_FILES,
            scope=scope,
            start_year=start_year,
            until_year=until_year,
            zones_map=zones_map,
            links_map=links_map,
            rules_map=rules_map,
            removed_zones=removed_zones,
            removed_links=removed_links,
            removed_policies=removed_policies,
            notable_zones=notable_zones,
            notable_links=notable_links,
            notable_policies=notable_policies,
            format_strings=format_strings,
            zone_strings=zone_strings,
        )
        generator.generate_files(output_dir)
    else:
        raise Exception("Unrecognized language '%s'" % language)


def main() -> None:
    """
    Main driver for TZ Database compiler which parses the IANA TZ Database files
    located at the --input_dir and generates zoneinfo files and validation
    datasets for unit tests at --output_dir.

    Usage:
        tzcompiler.py [flags...]
    """
    # Configure command line flags.
    parser = argparse.ArgumentParser(description='Generate Zone Info.')

    # Extractor flags.
    parser.add_argument(
        '--input_dir', help='Location of the input directory', required=True)

    # Transformer flags.
    parser.add_argument(
        '--scope',
        # basic: 241 of the simpler time zones for BasicZoneSpecifier
        # extended: all 348 time zones for ExtendedZoneSpecifier
        choices=['basic', 'extended'],
        help='Size of the generated database (basic|extended)',
        required=True)
    parser.add_argument(
        '--start_year',
        help='Start year of Zone Eras (default: 2000)',
        type=int,
        default=2000)
    parser.add_argument(
        '--until_year',
        help='Until year of Zone Eras (default: 2038)',
        type=int,
        default=2038)
    parser.add_argument(
        '--granularity',
        help=(
            'Truncate UNTIL, AT, SAVE and RULES fields to '
            + 'this many seconds (default: 60)'
        ),
        type=int)
    parser.add_argument(
        '--until_at_granularity',
        help=(
            'Truncate UNTIL and AT fields to this many seconds '
            + '(default: --granularity)'
        ),
        type=int)
    parser.add_argument(
        '--offset_granularity',
        help=(
            'Truncate SAVE, RULES (offset) fields to this many seconds'
            + '(default: --granularity)'
        ),
        type=int)
    parser.add_argument(
        '--strict',
        help='Remove zones and rules not aligned at granularity time boundary',
        action='store_true',
        default=False)

    # Data pipeline selectors:
    parser.add_argument(
        '--action',
        # zonedb: generate zonedb files
        # zonelist: generate zones.txt, list of relavant zones
        choices=['zonedb', 'zonelist'],
        help='Data pipeline action selector',
        required=True)

    # Language selector (for --action zonedb)
    parser.add_argument(
        '--language',
        choices=['arduino', 'python', 'json'],
        help='Target language (arduino|python|json)',
    )

    # C++ namespace names for '--language arduino'. If not specified, it will
    # automatically be set to 'zonedb' or 'zonedbx' depending on the 'scope'.
    parser.add_argument(
        '--db_namespace',
        help='C++ namespace for the zonedb files (default: zonedb or zonedbx)')

    # Enable zone_strings.{h,cpp} if requested. For '--language arduino'.
    parser.add_argument(
        '--generate_zone_strings',
        help='Generate Arduino zone_strings.{h,cpp} files',
        action='store_true')

    # Options for file generators
    parser.add_argument(
        '--tz_version', help='Version string of the TZ files', required=True)
    parser.add_argument(
        '--output_dir', help='Location of the output directory')

    # Parse the command line arguments
    args = parser.parse_args()

    # Configure logging. This should normally be executed after the
    # parser.parse_args() because it allows us set the logging.level using a
    # flag.
    logging.basicConfig(level=logging.INFO)

    # How the script was invoked
    invocation = ' '.join(sys.argv)

    # Define scope-dependent granularity if not overridden by flag
    if args.granularity:
        until_at_granularity = args.granularity
        offset_granularity = args.granularity
    else:
        if args.until_at_granularity:
            until_at_granularity = args.until_at_granularity
        else:
            until_at_granularity = 60

        if args.offset_granularity:
            offset_granularity = args.offset_granularity
        else:
            if args.scope == 'basic':
                offset_granularity = 900
            else:
                offset_granularity = 60

    logging.info('Using UNTIL/AT granularity: %d', until_at_granularity)
    logging.info(
        'Using RULES/SAVE (offset) granularity: %d',
        offset_granularity)

    # Extract the TZ files
    logging.info('======== Extracting TZ Data files')
    extractor = Extractor(args.input_dir)
    extractor.parse()
    extractor.print_summary()
    rules_map, zones_map, links_map = extractor.get_data()

    # Transform the TZ zones and rules
    logging.info('======== Transforming Zones and Rules')
    logging.info('Extracting years [%d, %d)', args.start_year, args.until_year)
    transformer = Transformer(
        zones_map,
        rules_map,
        links_map,
        args.scope,
        args.start_year,
        args.until_year,
        until_at_granularity,
        offset_granularity,
        args.strict,
    )
    transformer.transform()
    transformer.print_summary()
    (
        zones_map, rules_map, links_map, removed_zones, removed_policies,
        removed_links, notable_zones, notable_policies, notable_links,
        format_strings, zone_strings,
    ) = transformer.get_data()

    # Generate internal versions of zone_infos and zone_policies
    # so that ZoneSpecifier can be created.
    logging.info('======== Generating inlined zone_infos and zone_policies')
    inline_generator = InlineGenerator(zones_map, rules_map)
    (zone_infos, zone_policies) = inline_generator.generate_maps()
    logging.info('zone_infos=%d; zone_policies=%d', len(zone_infos),
                 len(zone_policies))

    if args.action == 'zonedb':
        generate_zonedb(
            invocation=invocation,
            tz_version=args.tz_version,
            tz_files=Extractor.ZONE_FILES,
            scope=args.scope,
            db_namespace=args.db_namespace,
            zones_map=zones_map,
            links_map=links_map,
            rules_map=rules_map,
            removed_zones=removed_zones,
            removed_links=removed_links,
            removed_policies=removed_policies,
            notable_zones=notable_zones,
            notable_links=notable_links,
            notable_policies=notable_policies,
            format_strings=format_strings,
            zone_strings=zone_strings,
            zone_infos=zone_infos,
            zone_policies=zone_policies,
            language=args.language,
            start_year=args.start_year,
            until_year=args.until_year,
            output_dir=args.output_dir,
            generate_zone_strings=args.generate_zone_strings,
        )
    elif args.action == 'zonelist':
        generator = ZoneListGenerator(
            invocation=invocation,
            tz_version=args.tz_version,
            tz_files=Extractor.ZONE_FILES,
            scope=args.scope,
            zones_map=zones_map)
        generator.generate_files(args.output_dir)
    else:
        logging.error(f"Unrecognized action '{args.action}'")
        sys.exit(1)

    logging.info('======== Finished processing TZ Data files.')


if __name__ == '__main__':
    main()
