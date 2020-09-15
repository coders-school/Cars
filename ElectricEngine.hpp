#pragma once

#include "Engine.hpp"

class ElectricEngine : public Engine {
public:
    ElectricEngine(uint16_t power, uint16_t batteryCapacity);
    uint16_t getBatteryCapacity() const { return batteryCapacity_; }

private:
    uint16_t batteryCapacity_;  // in Ah
};
