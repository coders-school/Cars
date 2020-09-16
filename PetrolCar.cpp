#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : petrolEngine_(std::move(engine))
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