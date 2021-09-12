#pragma once
#include "Engine.hpp"

class ElectricEngine : public Engine {
public:
    ElectricEngine(Engine::HorsePower power, int batteryCapacity);

private:
    int batteryCapacity_;  // in Ah
};
