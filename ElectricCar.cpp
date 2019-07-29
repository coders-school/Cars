#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

 ElectricCar::~ElectricCar()
 {
    delete engine_; 
    std::cout << __FUNCTION__ << std::endl; 
}

void ElectricCar::fill()
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricEngine ElectricCar::getElectricEngine() const
{
	std::cout << __FUNCTION__ << std::endl;
    return *engine_;
}