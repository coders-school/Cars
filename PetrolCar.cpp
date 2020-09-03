#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(PetrolEngine *engine)
    : petrolEngine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::refuel()
{
}

void PetrolCar::restore() {
    refuel();
}