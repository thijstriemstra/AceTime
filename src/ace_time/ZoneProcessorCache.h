/*
 * MIT License
 * Copyright (c) 2019 Brian T. Park
 */

#ifndef ACE_TIME_ZONE_PROCESSOR_CACHE_H
#define ACE_TIME_ZONE_PROCESSOR_CACHE_H

#include "common/common.h"
#include "TimeOffset.h"
#include "OffsetDateTime.h"
#include "BasicZoneProcessor.h"
#include "ExtendedZoneProcessor.h"
#include "ZoneRegistrar.h"

namespace ace_time {

/**
 * Common interface to BasicZoneProcessorCache and ExtendedZoneProcessorCache.
 * This allows ZoneManager to hold only a single implementation of
 * ZoneProcessorCache, and avoid loading the code for both implementations.
 */
class ZoneProcessorCache {
  public:
    /**
     * Return the type of this cache, either ZoneProcessor::kTypeBasic, or
     * ZoneProcessor::kTypeExtended.  TODO: This may not be used anywhere, so
     * it may be possible to remove it.
     */
    uint8_t getType() const { return mType; }

  protected:
    ZoneProcessorCache(uint8_t type)
      : mType(type)
    {}

  private:
    // disable copy constructor and assignment operator
    ZoneProcessorCache(const ZoneProcessorCache&) = delete;
    ZoneProcessorCache& operator=(const ZoneProcessorCache&) = delete;

    uint8_t const mType;
};

/**
 * A cache of ZoneProcessors that provides a ZoneProcessor to the TimeZone
 * upon request.
 *
 * @tparam SIZE number of zone processors, should be approximate the number
 *    zones *concurrently* used in the app. It is expected that this will be
 *    small. It can be 1 if the app never changes the TimeZone. It should be 2
 *    if the user is able to select different timezones from a menu.
 * @tparam TYPE integer constant identifying the type of TimeZone (e.g.
 *    ZoneProcessor::kTypeBasic, ZoneProcessor::kTypeExtended)
 * @tparam ZP type of ZoneProcessor (BasicZoneProcessor or
 *    ExtendedZoneProcessor)
 */
template<uint8_t SIZE, uint8_t TYPE, typename ZP>
class ZoneProcessorCacheImpl: public ZoneProcessorCache {
  public:
    ZoneProcessorCacheImpl()
      : ZoneProcessorCache(TYPE)
    {}

    /**
     * Get ZoneProcessor from either a ZoneKey, either a basic::ZoneInfo or an
     * extended::ZoneInfo. This will never return nullptr.
     */
    ZP* getZoneProcessor(uintptr_t zoneKey) {
      ZP* zoneProcessor = findUsingZoneKey(zoneKey);
      if (zoneProcessor) return zoneProcessor;

      // Allocate the next ZoneProcessor in the cache using round-robin.
      zoneProcessor = &mZoneProcessors[mCurrentIndex];
      mCurrentIndex++;
      if (mCurrentIndex >= SIZE) mCurrentIndex = 0;
      zoneProcessor->setZoneKey(zoneKey);
      return zoneProcessor;
    }

    /** Return the ZoneProcessor at position i. Used for initialization. */
    ZP* getZoneProcessor(uint8_t i) {
      return &mZoneProcessors[i];
    }

  private:
    // disable copy constructor and assignment operator
    ZoneProcessorCacheImpl(const ZoneProcessorCacheImpl&) = delete;
    ZoneProcessorCacheImpl& operator=(const ZoneProcessorCacheImpl&) = delete;

    /**
     * Find an existing ZoneProcessor with the ZoneInfo given by zoneInfoKey.
     * Returns nullptr if not found. This is a linear search, which should
     * be perfectly ok if SIZE is small, say <= 5.
     */
    ZP* findUsingZoneKey(uintptr_t zoneKey) {
      for (uint8_t i = 0; i < SIZE; i++) {
        ZP* zoneProcessor = &mZoneProcessors[i];
        if (zoneProcessor->equalsZoneKey(zoneKey)) {
          return zoneProcessor;
        }
      }
      return nullptr;
    }

    uint8_t mCurrentIndex = 0;
    ZP mZoneProcessors[SIZE];
};

#if 1
template<uint8_t SIZE>
class BasicZoneProcessorCache: public ZoneProcessorCacheImpl<
    SIZE,
    BasicZoneProcessor::kTypeBasic,
    BasicZoneProcessor> {
};

template<uint8_t SIZE>
class ExtendedZoneProcessorCache: public ZoneProcessorCacheImpl<
    SIZE,
    ExtendedZoneProcessor::kTypeExtended,
    ExtendedZoneProcessor> {
};
#else

// NOTE: The following typedef seems shorter and easier to maintain. The
// problem is that it makes error messages basically impossible to decipher
// because the immensely long full template class name is printed out. There
// seems to be no difference in code size between the two. The compiler seems
// to optimize away the vtables of the parent and child classes.

template<uint8_t SIZE>
using BasicZoneProcessorCache = ZoneProcessorCacheImpl<
    SIZE,
    ZoneProcessor::kTypeBasic,
    BasicZoneProcessor>;

template<uint8_t SIZE>
using ExtendedZoneProcessorCache  = ZoneProcessorCacheImpl<
    SIZE,
    ZoneProcessor::kTypeExtended,
    ExtendedZoneProcessor>;
#endif

}

#endif
