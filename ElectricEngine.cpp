#include "ElectricEngine.hpp"
#include <iostream>
#include <memory>

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : power_(power), batteryCapacity_(batteryCapacity) {
    std::cout << __FUNCTION__ << std::endl;
}
