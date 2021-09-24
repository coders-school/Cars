#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(int power, float capacity)
    : Engine(power, capacity)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricEngine::~ElectricEngine() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricEngine::fillUp() {
    std::cout << __FUNCTION__ << std::endl;
}

int ElectricEngine::getMaxSpeed() {
    return power_ * capacity_ / 300;
}

int ElectricEngine::getMaxReverseSpeed() {
    return getMaxSpeed() / 5 * (-1);
}
