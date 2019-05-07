#pragma once

#include "Engine.h"

class ElectricEngine : public Engine
{
public:
    ~ElectricEngine() = default;
    ElectricEngine(int power, int batteryCapacity);

    int power_;             // in HP 
    int batteryCapacity_;   // in Ah
};

