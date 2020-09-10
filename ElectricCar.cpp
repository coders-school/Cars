#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine) : engine_(std::move(engine))
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar()
{
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::charge()
{
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::restore()
{
    charge();
}