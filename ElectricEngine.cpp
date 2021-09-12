#include "ElectricEngine.hpp"
#include <iostream>
#include "Engine.hpp"

ElectricEngine::ElectricEngine(Engine::HorsePower power, AmpereHour batteryCapacity)
    : Engine(power), batteryCapacity_(batteryCapacity) {
    std::cout << __FUNCTION__ << std::endl;
}
