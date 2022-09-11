#include "ElectricCar.hpp"

#include <iostream>

ElectricCar::ElectricCar(const ElectricEngine& engine)
    : engine_(engine)
{
    std::cout << "ElectricCar::" << __FUNCTION__ << " (copying engine)" << std::endl;
}

ElectricCar::ElectricCar(ElectricEngine&& engine)
    : engine_(engine)
{
    std::cout << "ElectricCar::" << __FUNCTION__ << " (moving engine)" << std::endl;
}

ElectricCar::~ElectricCar()
{
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::refill()
{
    std::cout << "ElectricCar::" << __FUNCTION__ << std::endl;
    charge();
}

void ElectricCar::charge()
{
    std::cout << "ElectricCar::" << __FUNCTION__ << std::endl;
}
