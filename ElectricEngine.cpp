#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : Engine(power), batteryCapacity_(batteryCapacity) {}
