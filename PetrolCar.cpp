#include "PetrolCar.hpp"

#include <iostream>

PetrolCar::PetrolCar(const PetrolEngine& engine)
    : engine_(engine)
{
    std::cout << "PetrolCar::" << __FUNCTION__ << " (copying engine)" << std::endl;
}

PetrolCar::PetrolCar(PetrolEngine&& engine)
    : engine_(engine)
{
    std::cout << "PetrolCar::" << __FUNCTION__ << " (moving engine)" << std::endl;
}

PetrolCar::~PetrolCar()
{
    std::cout << "PetrolCar::" << __FUNCTION__ << std::endl;
}

void PetrolCar::refill()
{
    std::cout << "PetrolCar::" << __FUNCTION__ << std::endl;
    refuel();
}

void PetrolCar::refuel()
{
    std::cout << "PetrolCar::" << __FUNCTION__ << std::endl;
}
