#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(PetrolEngine *engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::addEnergy() { refuel(); }
void PetrolCar::refuel() { std::cout << __FUNCTION__ << std::endl; }
int PetrolCar::getGear(){ 
    return this -> engine_ -> getCurrentGear();
}
void PetrolCar::setGear(int value)
{
    return this -> engine_ ->changeGear(value);
}

