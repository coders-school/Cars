#pragma once

#include "HorsePower.hpp"

class AmpereHour {
   public:
    int value_;
    explicit AmpereHour(int value) :
            value_(value) {}
};
class ElectricEngine {
    HorsePower power_;
    AmpereHour batteryCapacity_;  // in Ah

   public:
    ElectricEngine(HorsePower power, AmpereHour batteryCapacity);
    ~ElectricEngine();
};
