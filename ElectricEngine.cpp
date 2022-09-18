#include "ElectricEngine.hpp"

#include <iostream>

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : power_(power)
    , batteryCapacity_(batteryCapacity)
{
    std::cout << "ElectricEngine::" << __FUNCTION__ << std::endl;
}

int ElectricEngine::power() const
{
    return power_;
}

int ElectricEngine::batteryCapacity() const
{
    return batteryCapacity_;
}