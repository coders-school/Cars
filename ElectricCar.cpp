#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* electricEng)
    : engine_(electricEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar()
{
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::brake()
{
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::accelerate(int speed)
{
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::charge()
{
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::topUp()
{
    charge();
}
