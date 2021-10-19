#pragma once
#include "Engine.hpp"

class ElectricEngine : public Engine
{
public:
    ElectricEngine(int power, int batteryCapacity);

    int batteryCapacity_;   // in Ah
};

