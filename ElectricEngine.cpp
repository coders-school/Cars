#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : Engine(power)
    , batteryCapacity_(batteryCapacity)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricEngine::~ElectricEngine()
{
    std::cout << __FUNCTION__ << std::endl;
}

std::ostream & operator<<(std::ostream & out, ElectricEngine const & engine)
{
    out << "Electric engine::  power: "<< engine.getPower() 
        << "\tCapacity: " << engine.getBatteryCapacity();

    return out;
}  