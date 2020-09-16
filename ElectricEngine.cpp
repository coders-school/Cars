#include "ElectricEngine.hpp"
#include <iostream>
#include <memory>

ElectricEngine::ElectricEngine(int power, int batteryCapacity, int currentCapacity)
    : power_(power), batteryCapacity_(batteryCapacity), currentCapacity_(currentCapacity) {
    std::cout << __FUNCTION__ << std::endl;
}
