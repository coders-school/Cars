#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng, int vmax)
    : PetrolCar(petrolEng, vmax)
    , ElectricCar(electricEng, vmax)
{
    Car::Vmax = vmax;
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar()         {std::cout << __FUNCTION__ << std::endl;}
void HybridCar::feed() {
    PetrolCar::feed();
    ElectricCar::feed();
 }
