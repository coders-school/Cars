#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : power_(power)
    , batteryCapacity_(batteryCapacity)
    , gears_(1)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricEngine::~ElectricEngine()
{
    std::cout << __FUNCTION__ << std::endl;
}

int ElectricEngine::getGear()
{
    return currentGear_;
}

bool ElectricEngine::isGearValid(int& gear)
{
    return (gear <= gears_ && gear >= -1) ? true : false;
}

