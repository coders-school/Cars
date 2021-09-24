#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : power_(power), batteryCapacity_(batteryCapacity) {
    std::cout << __FUNCTION__ << std::endl;
}

bool ElectricEngine::validation(int value){
    return value < 0;
}

int ElectricEngine::getPower() {
    return power_;
}

int ElectricEngine::getBatteryCapacity() {
    return batteryCapacity_;
}

void ElectricEngine::setPower(int power){
    if (validation(power)) {
        std::cout << "power cannot be negative " << std::endl;
    } else {
        power_ = power;
    } 
}

void ElectricEngine::setBatteryCapacity(int batteryCapacity) {
    if (validation(batteryCapacity)) {
        std::cout << "batteryCapacity cannot be negative " << std::endl;
    } else {
         batteryCapacity_ = batteryCapacity;
    }
}