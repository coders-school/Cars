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
    AmpereHour batteryCapacity_;

   public:
    ElectricEngine(HorsePower power, AmpereHour batteryCapacity);
    ~ElectricEngine();
    HorsePower getPower() const { return power_; };
    AmpereHour getBatterCapacity() const { return batteryCapacity_; };
};
