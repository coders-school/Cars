#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(int power, int maxBatteryCapacity, int currentBatteryCapacity)
    : power_(power), maxBatteryCapacity_(maxBatteryCapacity), currentBatteryCapacity_(currentBatteryCapacity) {
    std::cout << __FUNCTION__ << std::endl;
}
