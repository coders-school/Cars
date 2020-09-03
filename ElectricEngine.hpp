#pragma once

#include "Engine.hpp"

class ElectricEngine : public Engine {
public:
    ElectricEngine(int power, int batteryCapacity);

    // Override from Engine
    ~ElectricEngine() override;

    int getBatteryCapacity() const;

private:
    int batteryCapacity_;  // in Ah
};
