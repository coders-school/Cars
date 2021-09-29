#include "ElectricEngine.hpp"
#include <iostream>
#include <stdexcept>

ElectricEngine::ElectricEngine(int power, int batteryCapacity) {
    try {
        if (ConstructorDataTest(power, batteryCapacity))
            std::cout << __FUNCTION__ << std::endl;
        power_ = power;
        batteryCapacity_ = batteryCapacity;
    } catch (const std::invalid_argument& arg) {
        std::cout << arg.what() << std::endl;
    }
}
bool ElectricEngine::ConstructorDataTest(int power, int batteryCapacity) {
    if (power < 0 || batteryCapacity < 0) {
        throw std::invalid_argument("negative value of the parameter ");
    }
    return true;
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