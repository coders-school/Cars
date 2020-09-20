#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar()
{
    std::cout << __FUNCTION__ << std::endl;
    delete engine_;
}
void ElectricCar::charge()
{
    std::cout << __FUNCTION__ << std::endl;
}
