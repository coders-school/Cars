#include "ElectricCar.hpp"

#include <iostream>

ElectricCar::ElectricCar(Engine* engine)
    : Car(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl; 
}

void ElectricCar::accelerate(int) { 
    std::cout << __FUNCTION__ << std::endl; 
}
