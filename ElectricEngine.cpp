#include "ElectricEngine.hpp"
#include <iostream>
#include "Engine.hpp"

ElectricEngine::ElectricEngine(const Engine::HorsePower& power, const AmpereHour& batteryCapacity)
    : Engine(power), batteryCapacity_(batteryCapacity) {
    std::cout << __FUNCTION__ << std::endl;
}
