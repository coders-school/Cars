#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    // : Engine(power)
    : power_(power)
    , batteryCapacity_(batteryCapacity)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricEngine::~ElectricEngine() {
    std::cout << __FUNCTION__ << std::endl;
}
