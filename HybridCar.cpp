#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
    : PetrolCar(petrolEng)
    , ElectricCar(electricEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar()
{
    delete ElectricCar::engine_;
    delete PetrolCar::engine_;
    std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::feed() {
    PetrolCar::feed();
    ElectricCar::feed();
 }
