#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : Engine(power)
    , batteryCapacity_(batteryCapacity)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricEngine::~ElectricEngine() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricEngine::charge() {
    std::cout << __FUNCTION__ << " batery capacity: " << batteryCapacity_ << "Ah" <<std::endl;
}