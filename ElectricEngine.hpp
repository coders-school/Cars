#pragma once
#include "Engine.hpp"

class ElectricEngine : virtual public Engine
{
public:
    ElectricEngine(int power, int batteryCapacity);
    // int power_;             // in HP 

private:
    int batteryCapacity_;   // in Ah
};
