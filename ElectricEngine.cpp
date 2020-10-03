#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(Power power, BatteryCapacity batteryCapacity)
    : power_(power), batteryCapacity_(batteryCapacity) {
  std::cout << __FUNCTION__ << std::endl;
}

ElectricEngine::~ElectricEngine() { std::cout << __FUNCTION__ << std::endl; }
void ElectricEngine::start() const { std::cout << __FUNCTION__ << std::endl; };
void ElectricEngine::stop() const { std::cout << __FUNCTION__ << std::endl; };
