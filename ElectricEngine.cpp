#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : power_(power), batteryCapacity_(batteryCapacity) {
  std::cout << __FUNCTION__ << std::endl;
}

int ElectricEngine::getPower() const { return power_; }
int ElectricEngine::getBatteryCapacity() const { return batteryCapacity_; }
