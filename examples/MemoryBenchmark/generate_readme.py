#!/usr/bin/python3
#
# Python script that regenerates the README.md from the embedded template. Uses
# ./generate_table.awk to regenerate the ASCII tables from the various *.txt
# files.

from subprocess import check_output

nano_results = check_output(
    "./generate_table.awk < nano.txt", shell=True, text=True)
micro_results = check_output(
    "./generate_table.awk < micro.txt", shell=True, text=True)
samd21_results = check_output(
    "./generate_table.awk < samd21.txt", shell=True, text=True)
stm32_results = check_output(
    "./generate_table.awk < stm32.txt", shell=True, text=True)
samd51_results = check_output(
    "./generate_table.awk < samd51.txt", shell=True, text=True)
esp8266_results = check_output(
    "./generate_table.awk < esp8266.txt", shell=True, text=True)
esp32_results = check_output(
    "./generate_table.awk < esp32.txt", shell=True, text=True)

print(f"""\
# Memory Benchmark

The `MemoryBenchmark.ino` was compiled with each `FEATURE_*` and the flash
memory and static RAM sizes were recorded. The `FEATURE_BASELINE` selection is
the baseline, and its memory usage  numbers are subtracted from the subsequent
`FEATURE_*` memory usage.

**Version**: AceTime v2.3-dev

**DO NOT EDIT**: This file was auto-generated using `make README.md`.

## How to Regenerate

To regenerate this README.md:

```
$ make clean_benchmarks
$ make benchmarks
$ make README.md
```

The `make benchmarks` target uses `collect.sh` script which calls `auniter.sh`
(https://github.com/bxparks/AUniter) to invoke the Arduino IDE programmatically.
It produces a `*.txt` file with the flash and ram usage information (e.g.
`nano.txt`). It now takes about 16 minutes to generate the `*.txt` files on my
quad-core Intel Core i7-3840QM CPU @ 2.80GHz laptop.

The `make README.md` command calls the `generated_readme.py` Python script which
generates this `README.md` file. The ASCII tables below are generated by the
`generate_table.awk` script, which takes each `*.txt` file and converts it to an
ASCII table.

## Library Size Changes

**v1.3:**
* The `BasicZoneManager` and `ExtendedZoneManager` classes were unified under a
  new parent interface `ZoneManager`. This seems to have caused the flash size
  to increase by around 1200 bytes on the AVR processors (Nano, Pro Micro),
  about 500 bytes on a SAMD, about 800 bytes on a ESP8266, 100 bytes on a ESP32,
  and 1400 bytes on a Teensy 3.2. The 8-bit processors suffer the most flash
  size increase proportional to their limited 32kB limit.
* Adding the `ZoneManager` interface simplifies a lot of the complexity with
  saving and restoring time zones using the `TimeZoneData` object, and I think
  it is worth the extra cost of flash size. The mitigating factor is that
  applications targetted towards 8-bit processors will normally have fixed
  number of timezones at compile time, so they can avoid using a `ZoneManager`,
  and avoid this penalty in flash size.

**v1.4.1+:**
* Removed the `ZoneInfo::transitionBufSize` field from the `ZoneInfo` struct,
  which saves 1 byte on 8-bit processors (none on 32-bit processors due to
  4-byte alignment). We save 266 bytes for `BasicZoneManager` and 386 bytes for
  `ExtendedZoneManager` when all the zones are loaded into the zone registry.
* Incorporated zoneName compression causes flash/ram usage to increase by
  ~250/120 bytes when using only 1-2 zones, but *decreases* flash consumption by
  1200-2400 bytes when all the zones are loaded into the `ZoneManager`.

**v1.5+:**
* Changing `ZoneProcessorCache::getType()` from a `virtual` to a non-virtual
  method saves 250-350 bytes of flash memory when using a `BasicZoneManager` or
  an `ExtendedZoneManager` on an 8-bit AVR processor. Unexpectedly, the flash
  memory consumption *increases* slightly (~0-50 bytes) for some ARM processors
  and the ESP32. Since those processors have far more flash memory, this seems
  like a good tradeoff.
* Changing `BasicZoneProcessor` and `ExtendedZoneProcessor` to be subclasses of
  the templatized `BasicZoneProcessorTemplate` and
  `ExtendedZoneProcessorTemplate` classes causes reduction of flash consumption
  by 250-400 bytes for 32-bit processors. Don't know why. (Very little
  difference for 8-bit AVR).
* Adding a `ZoneInfoStore` layer of indirection (to support more complex
  ZoneProcessors and Brokers) causes flash memory to go up by 100-200 bytes.

**v1.6:**
* Added support for `LinkRegistry` to `BasicZoneManager` and
  `ExtendedZoneManager`. This increases the flash memory usage by 150-500 bytes
  when using one of these classes due to the code required by `LinkRegistrar`. This extra cost is incurred even if the `LinkRegistry` is set to 0 elements. Each `LinkEntry` consumes 8 bytes (2 x `uint32_t`). So a
  `zonedb::kLinkRegistry` with 183 elements uses 1464 extra bytes of flash; a
  `zonedbx::kLinkRegistry` with 207 elements uses 1656 extra bytes.

**v1.7:**
* The virtual destructor on the `Clock` base class removed. This reduced the
  flash usage by 618 bytes on AVR processors , 328 bytes on the SAMD21, but only
  50-60 bytes on other 32-bit processors.
* The various `printShortNameTo()` or `printShortTo()` methods changed to
  replace the underscore in the zone names (e.g. `Los_Angeles`) with spaces
  (e.g. `Los Angeles`) to be more human friendly. This made little difference in
  the flash memory consumption, except on the ESP32 where it increased by
  200-300 bytes.

**v1.7.2**
* The `SystemClock::clockMillis()` is now non-virtual, using compile-time
  polymorphism through C++ template, and incorporating the same techniques from
  AceRoutine v1.3. Saves about 20-40 bytes of flash.

**v1.7.5:**
* `ExtendedZoneProcessor.compareTransitionToMatch()` was modified to
  detect an exact equality between a `Transition` and its `MatchingEra` if any
  of the 3 time stamp versions ('w', 's', 'u') are equal. Adds about 120-150
  bytes of flash on 8-bit and 32-bit processors. But removing
  `originalTransitionTime` from `Transition` decreases flash usage by about 20
  bytes.
* Upgrade ESP8266 Boards from 2.7.4 to 3.0.2. Flash consumption increases by
  3-5 kB across the board.
* Upgrade Teensyduino from 1.54 to 1.55. Add memory consumed by `malloc()` and
  `free()` when using classes with virtual methods into baseline
  MemoryBenchmark, reducing the actual memory usage of various features by
  ~3kB.

**v1.8.0:**
* Move Clock and SystemClock benchmarks into AceTimeClock v1.0.0.
* Extract thin links from BasicZoneManager and ExtendedZoneManager into
  new BasicLinkManager and ExtendedLinkManager classes.
    * Saves 200-500 bytes of flash for BasicZoneManager and ExtendedZoneManager.
    * Applications can decide whether to use thin links through the LinkManager
      (~2000 flash bytes for AVR) or use fat links through the
      `kZoneAndLinkRegistry` (~5000 flash bytes for AVR).
* Create various test objects as global variables instead of stack variables
  to get a more accurate measurement of their static memory consumption.

**v1.9.0:**
* Reduce flash usage of `BasicZoneManager` and `ExtendedZoneManager` by
  1100-1300 bytes on AVR processors:
    * Extract `BasicZoneProcessorCache` and `ExtendedZoneProcessorCache` out
      of `BasicZoneManager` and `ExtendedZoneManager`, making them
      non-templatized.
    * Remove all `virtual` methods from `ZoneManager`, making the ZoneManager
      hierarchy non-polymorphic.
    * Looks like I am reverting some of the changes made in v1.3 when I created
      the `ZoneManager` interface.
* Reduce flash usage of `BasicLinkManager` and `ExtendedLinkManager` by
  68 bytes on AVR processors by removing pure `virtual` methods on `LinkManager`
  base class.
* Increase flash usage by 34 bytes on AVR processors due to slight refactoring
  of `getHighWater()` with `getAllocSize()`. Only 4-8 bytes increase on 32-bit
  processors.

**v1.10.0:**
* Remove support for SAMD21 boards.
    * Arduino IDE 1.8.19 with SparkFun SAMD 1.8.6 can no longer upload binaries
      to these boards. Something about bossac 1.7.0 not found.
* Add memory consumption benchmarks for `ZoneSorterByName` and
  `ZoneSorterByOffsetAndName` for `BasicZoneManager` and `ExtendedZoneManager`.
    * AVR: 180-530 bytes of flash
    * 32-bit: 120-600 bytes of flash
* Upgrade tool chain:
    * Arduino IDE from 1.8.13 to 1.8.19
    * Arduino AVR from 1.8.3 to 1.8.4
    * STM32duino from 2.0.0 to 2.2.0
    * ESP32 from 1.0.6 to 2.0.2
    * Teensyduino from 1.55 to 1.56
* Add support for `fold` parameter in `LocalDateTime`, `OffsetDateTime`,
  `ZonedDateTime`, and `ExtendedZoneProcessor`. Increases flash usage:
    * AVR:
        * ~600 bytes, in `ExtendedZoneProcessor` for additional search logic,
        * ~150 bytes, `BasicZoneProcessor`, to carry along the `fold` parameter
    * most 32-bit: 400-600 bytes
    * Teensy: 1300 bytes (no idea why)

**v1.11.0**
* Upgrade ZoneInfo database so that Links are symbolic links to Zones, instead
  of hard links to Zones.
    * Allows Links to know whether they are links.
    * Allows extraction of the zoneId and zoneNames of the target Zone.
    * AVR: Increases flash consumption by ~270 bytes.
    * STM32: Increases flash by 120-150 bytes.
    * ESP8266: Increases flash by 250-300 bytes.
    * ESP32: Increases flash by ~190 bytes.
    * Teensy 3.2: Increase flash by 450-1300 bytes.

**v1.11.1**
* Change `ZoneInfoBroker::targetZoneInfo()` method to return a `ZoneInfoBroker`
  instead of raw `ZoneInfo*` pointer.
    * Increases flash usage by 4-16 bytes for the most part.

**v1.11.5**
* Upgrade tool chain
    * Arduino CLI from 0.20.2 to 0.27.1
    * Arduino AVR Boards from 1.8.4 to 1.8.5
    * STM32duino from 2.2.0 to 2.3.0
    * ESP32 Boards from 2.0.2 to 2.0.5
    * Teensyduino from 1.56 to 1.57
* Upgrade TZDB from 2022b to 2022d

**v2.0**
* Use `int16_t` year fields.
* Implement adjustable epoch year.
* Upgrade to TZDB 2022f.
* AVR:
    * BasicZoneManager increases ~200 bytes
    * ExtendedZoneManager increases ~500 bytes
    * `zonedb` increases ~1.5 kiB
    * `zonedbx` increases ~3 kiB
* ESP8266
    * BasicZoneManager increases ~50 bytes
    * ExtendedZoneManager increases ~150 bytes
    * `zonedb` increases ~300 bytes
    * `zonedbx` increases ~1.5 kiB

**v2.0.1**
* Upgrade to TZDB 2022g.
* Incorporate `ZonedExtra` to replace various `TimeZone` methods.

**v2.1.0**
* Remove `LinkManager` and `LinkRegistry`.
* Unify links, adding an additional `targetInfo` field in `ZoneInfo`.
    * Increases flash by ~1kB on 8-bit and ~2kB on 32-bit for ~600 zones.

**v2.1.1+**
* Simplify ZoneRule.letter handling to use ZoneRule.letterIndex for all letters,
  not just ones over 1 character long. On 8-bit AVR:
    * BasicZoneProcessor
        * Increases flash consumption for 1-2 zones by ~200 bytes.
        * No change for the full TZ database.
    * ExtendedZoneProcessor
        * No change for 1-2 zones.
        * Decreases flash consumption by ~300 bytes for full TZ database.

**v2.2.0**
* Upgrade tool chain
    * Arduino AVR from 1.8.5 to 1.8.6
    * STM32duino from 2.3.0 to 2.4.0
    * ESP8266 from 3.0.2 to 3.1.2 failed, reverted back to 3.0.2
    * ESP32 from 2.0.5 to 2.0.7
* Add support for Seeed XIAO SAMD21
    * Using Seeeduino SAMD Boards 1.8.3
* Upgrade to TZDB 2023b

**v2.2.2**
* Upgrade to TZDB 2023c

**v2.2.3**
* Add support for Adafruit ItsyBitsy M4
    * Using Adafruit SAMD Boards 1.7.11
* Remove Teensy 3.2
    * Nearing end of life. Moved to Tier 2 (should work).
* Upgrade tool chain
    * Seeeduino SAMD Boards 1.8.4
    * STM32duino Boards 2.5.0
    * ESP32 Boards 2.0.9

**v2.3-dev**
* Implement 1-second resolution in ExtendedZoneProcessor.
    * Increases flash usage by ~1kB on 8-bit processors, but only 0-100 bytes
      on 32-bit processors.
* Implement CompleteZoneProcessor as a specialization of ExtendedZoneProcessor.
    * Enables the creation of `zonedbc` database which contains all TZDB
      timezones, for all years going back to 1844, the earliest transition in
      the TZDB.
    * The flash consumption of zonedbc is roughly 2X of zonedbx.
* Revert `zonedb` to use 8-bit year fields.
    * Increases memory consumption for BasicZoneManager w/ 1 zone by around
      150 bytes.
    * Decreases memory cosumption for BasicZoneManager w/ all timezones by
      800-900 bytes.
* Move ZoneContext and its string arrays into PROGMEM.
    * Reduces RAM usage by 150-200 bytes on AVR and ESP8266 processors.
* Merge `createAbbreviation()`
    * `BasicZoneProcessor`: Slight (30-60 bytes) increase in flash memory,
      no change in RAM usage.
    * `ExtendedZoneProcessor`: Slight (30-60 bytes) increase in flash memory.
      But saves ~16 bytes of RAM for 8-bit, ~64 bytes of RAM for 32-bit.

# Legend

* [1] Delta flash and ram consumption for `Basic ZoneSorterByName` and
  `Basic ZoneSorterByOffsetAndName` are calculated by subtracting the
  `BasicZoneManager (1 zone)` numbers, to isolate the memory consumption
  of just the sorter classes.
* [2] Delta flash and ram consumption for `Extended ZoneSorterByName` and
  `Extended ZoneSorterByOffsetAndName` are calculated by subtracting the
  `ExtendedZoneManager (1 zone)` numbers, to isolate the memory
  consumption of just the sorter classes.
* [3] Delta flash and ram consumption for `Complete ZoneSorterByName` and
  `Complete ZoneSorterByOffsetAndName` are calculated by subtracting the
  `CompleteZoneManager (1 zone)` numbers, to isolate the memory
  consumption of just the sorter classes.
* An entry of `-1` indicates that the memory usage exceeded the maximum of the
  microcontroller and the compiler did not generate the desired information.

## Arduino Nano

* 16MHz ATmega328P
* Arduino IDE 1.8.19, Arduino CLI 0.31.0
* Arduino AVR Boards 1.8.6

```
{nano_results}
```

## Sparkfun Pro Micro

* 16 MHz ATmega32U4
* Arduino IDE 1.8.19, Arduino CLI 0.31.0
* SparkFun AVR Boards 1.1.13

```
{micro_results}
```

## Seeed Studio XIAO SAMD21

* SAMD21, 48 MHz ARM Cortex-M0+
* Arduino IDE 1.8.19, Arduino CLI 0.31.1
* Seeeduino SAMD Boards 1.8.4

```
{samd21_results}
```

## STM32 Blue Pill

* STM32F103C8, 72 MHz ARM Cortex-M3
* Arduino IDE 1.8.19, Arduino CLI 0.31.0
* STM32duino 2.5.0

```
{stm32_results}
```

## SAMD51 (Adafruit ItsyBitsy M4)

* SAMD51, 120 MHz ARM Cortex-M4
* Arduino IDE 1.8.19, Arduino CLI 0.31.0
* Adafruit SAMD 1.7.11

```
{samd51_results}
```
## ESP8266

* NodeMCU 1.0, 80MHz ESP8266
* Arduino IDE 1.8.19, Arduino CLI 0.31.0
* ESP8266 Boards 3.0.2

```
{esp8266_results}
```

## ESP32

* ESP32-01 Dev Board, 240 MHz Tensilica LX6
* Arduino IDE 1.8.19, Arduino CLI 0.31.0
* ESP32 Boards 2.0.9

```
{esp32_results}
```

RAM usage remains constant as more objects are created, which indicates that an
initial pool of a certain minimum size is created regardless of the actual RAM
usage by objects.
""")
