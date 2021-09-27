#include "ElectricEngine.hpp"
#include <iostream>
#include <stdexcept>

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : power_(power), batteryCapacity_(batteryCapacity) {
    if (power < 0 || batteryCapacity < 0) {
        throw std::invalid_argument("negative value of the parameter ");
    }

    std::cout << __FUNCTION__ << std::endl;
}

bool ElectricEngine::validation(int value) {
    return value < 0;
}

int ElectricEngine::getPower() {
    return power_;
}

int ElectricEngine::getBatteryCapacity() {
    return batteryCapacity_;
}

void ElectricEngine::setPower(int power) {
    if (validation(power)) {
        std::cout << "Power cannot be negative " << std::endl;
    } else {
        power_ = power;
    }
}

void ElectricEngine::setBatteryCapacity(int batteryCapacity) {
    if (validation(batteryCapacity)) {
        std::cout << "Battery capacity cannot be negative " << std::endl;
    } else {
        batteryCapacity_ = batteryCapacity;
    }
}