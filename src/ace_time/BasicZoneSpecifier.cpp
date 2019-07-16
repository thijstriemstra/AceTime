/*
 * MIT License
 * Copyright (c) 2019 Brian T. Park
 */

#include <Print.h>
#include "BasicZone.h"
#include "BasicZoneSpecifier.h"

namespace ace_time {

void BasicZoneSpecifier::printTo(Print& printer) const {
  printer.print(BasicZone(mZoneInfo.zoneInfo()).name());
}

void BasicZoneSpecifier::printShortTo(Print& printer) const {
  printer.print(BasicZone(mZoneInfo.zoneInfo()).shortName());
}

}

