#include "ElectricEngine.hpp"
#include <iostream>
#include "Engine.hpp"

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : Engine(power), batteryCapacity_(batteryCapacity) {
    std::cout << __FUNCTION__ << std::endl;
}
