#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng, int maxSpeed)
    : PetrolCar(petrolEng, maxSpeed)
    , ElectricCar(electricEng, maxSpeed)
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar()       { std::cout << __FUNCTION__ << std::endl; }
void HybridCar::feed() {
    PetrolCar::feed();
    ElectricCar::feed();
 }