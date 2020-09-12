#include "ElectricEngine.hpp"

#include <iostream>

ElectricEngine::ElectricEngine(uint16_t power, uint16_t batteryCapacity)
    : Engine(power), batteryCapacity_(batteryCapacity) {
    std::cout << __FUNCTION__ << std::endl;
}
