#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : power_(power)
    , batteryCapacity_(batteryCapacity)
{
    if(power_ < 1) {
        throw std::invalid_argument("Power can't be lower than 1");
    }
    if(batteryCapacity_ < 1) {
        throw std::invalid_argument("Capacity can't be lower than 1");
    }
    
    std::cout << __FUNCTION__ << std::endl;
}

int ElectricEngine::getElectricPower() const
{
	std::cout << __FUNCTION__ << std::endl;
    return power_;
}

int ElectricEngine::getBatteryCapacity() const
{
	std::cout << __FUNCTION__ << std::endl;
    return batteryCapacity_;
}
