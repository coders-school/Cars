#pragma once

#include "Engine.hpp"

class ElectricEngine : public virtual Engine
{
public:
    ElectricEngine(int power, int batteryCapacity);
    ~ElectricEngine() override = default;

    int power_;             // in HP 
    int batteryCapacity_;   // in Ah
};

