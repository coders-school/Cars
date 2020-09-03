#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
: electricEngine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar()       { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::restore() {
    charge();
}
