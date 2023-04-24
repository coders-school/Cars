#pragma once
#include "Engine.hpp"
class ElectricEngine : Engine
{
public:
    ElectricEngine(int power, int batteryCapacity);
    ~ElectricEngine() override;
private:
    int batteryCapacity_;   // in Ah
};

