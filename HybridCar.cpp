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
    std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::feed() 
{
    if (velocity == 0)
    {
        PetrolCar::feed();
        ElectricCar::feed();
    }
}
