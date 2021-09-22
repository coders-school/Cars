#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(int power, float capacity)
    : Engine(power, capacity)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricEngine::~ElectricEngine() {

}

void ElectricEngine::fillUp() {
    std::cout << __FUNCTION__ << std::endl;
}
