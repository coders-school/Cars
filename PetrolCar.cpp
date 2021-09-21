#include "PetrolCar.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(PetrolEngine* petrolEngine)
    : petrolEngine_(petrolEngine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() { 
    std::cout << __FUNCTION__ << std::endl; 
}

void PetrolCar::accelerate(int) {
    std::cout << __FUNCTION__ << std::endl; 
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl; 
}

