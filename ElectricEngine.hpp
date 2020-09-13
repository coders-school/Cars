#pragma once
#include "Engine.hpp"

class ElectricEngine : public Engine {
public:
    ElectricEngine(int power, int batteryCapacity);
    ~ElectricEngine();

    int getPower() const;
    int getBatteryCapacity() const;

private:
    int power_;            // in HP
    int batteryCapacity_;  // in Ah
};
