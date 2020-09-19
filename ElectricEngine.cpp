#include "ElectricEngine.hpp"

#include <iostream>

#include "Exceptions.hpp"

ElectricEngine::ElectricEngine(int power, int batteryCapacity) : Engine(power) {
    std::cout << __FUNCTION__ << std::endl;
    if (batteryCapacity <= 0) {
        throw InvalidParameter("Initial battery capacity cannot be lower or equal to zero.\n");
    }
    batteryCapacity_ = batteryCapacity;
}

int ElectricEngine::getBatteryCapacity() {
    return batteryCapacity_;
}
