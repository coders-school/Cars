#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(PetrolEngine* petrolEng)
    : engine_(petrolEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::turnLeft()
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::turnRight()
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

