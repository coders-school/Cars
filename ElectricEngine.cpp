#include "ElectricEngine.hpp"

#include <iostream>

#include "exception/InvalidParameter.hpp"

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : Engine(power)
{
    std::cout << __FUNCTION__ << std::endl;
    if (batteryCapacity <= 0) {
        throw InvalidParameter("> battery capacity cannot be negative!");
    }

    batteryCapacity_ = batteryCapacity;
}
