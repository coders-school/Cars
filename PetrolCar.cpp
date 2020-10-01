#include "PetrolCar.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()          { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::turnLeft() const      { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::turnRight() const    { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::brake()     const   { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::accelerate(int) const { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }

