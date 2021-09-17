#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : power_(power), batteryCapacity_(batteryCapacity) {
    std::cout << __FUNCTION__ << std::endl;
}

int ElectricEngine::getPower() {
    return power_;
}

int ElectricEngine::getBatteryCapacity() {
    return batteryCapacity_;
}

void ElectricEngine::setPower(int power){
    power_= power;
}

void ElectricEngine::setBatteryCapacity(int batteryCapacity) {
    batteryCapacity_ = batteryCapacity;
}