#include "ElectricEngine.hpp"

#include <iostream>

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : power_(power)
    , batteryCapacity_(batteryCapacity)
{
    std::cout << "ElectricEngine::" << __FUNCTION__ << std::endl;
}
