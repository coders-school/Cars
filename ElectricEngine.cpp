#include <iostream>

#include "ElectricEngine.hpp"

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : power_(power), batteryCapacity_(batteryCapacity) {
    std::cout << __FUNCTION__ << std::endl;
}
