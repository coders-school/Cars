#pragma once
#include "Engine.hpp"
#include <iostream>

class ElectricEngine : public Engine
{
public:
    ElectricEngine(int power, int batteryCapacity);
    // ~ElectricEngine() {}
    // ~ElectricEngine() override {}
    // void start() override {std::cout << "Engine started.\n";}

private:
    int power_;             // in HP 
    int batteryCapacity_;   // in Ah
};
