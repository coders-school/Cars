#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(PetrolEngine* petrolEng)
    : engine_(petrolEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::brake()
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::accelerate(int speed)
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::refuel()
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::topUp()
{
    refuel();
}

