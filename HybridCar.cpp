#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
    : PetrolCar(petrolEng)
    , ElectricCar(electricEng)
{
    std::cout << __FUNCTION__ << std::endl;
    this-> velocity = 0;
}

HybridCar::~HybridCar()       { std::cout << __FUNCTION__ << std::endl; }
void HybridCar::feed() 
{
    PetrolCar::feed();
    ElectricCar::feed();
}