#pragma once
#include "Engine.hpp"
class ElectricEngine : public Engine {
public:
    ElectricEngine(int power, int batteryCapacity);

private:
    int batteryCapacity_;  // in Ah
};
