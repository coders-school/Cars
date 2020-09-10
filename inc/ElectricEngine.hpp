#pragma once

#include "Engine.hpp"

class ElectricEngine : public Engine {
public:
    ElectricEngine(int power, int batteryCapacity);
    ~ElectricEngine();

    int getBatteryCapacity() const { return batteryCapacity_; }

private:
    int batteryCapacity_;   // in Ah
};
