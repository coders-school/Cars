#pragma once

#include "Engine.hpp"

class ElectricEngine : public Engine {
private:
    int batteryCapacity_;  // in Ah

public:
    ElectricEngine(int power, int batteryCapacity);
};
