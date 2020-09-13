#pragma once

#include "Engine.hpp"

class ElectricEngine : public Engine {
public:
    ElectricEngine(int power, int batteryCapacity);

    int getBatteryCapacity() const;

    // Override from Engine
    ~ElectricEngine() override;

private:
    int batteryCapacity_;  // in Ah
};
