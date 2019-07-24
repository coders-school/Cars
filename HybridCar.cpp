#include "HybridCar.hpp"
#include"Exceptions.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
    : PetrolCar(petrolEng)
    , ElectricCar(electricEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar()       { std::cout << __FUNCTION__ << std::endl; }
 

PetrolEngine * HybridCar::changeEngine(int power,float capacity,int gears)
{
    PetrolCar::changeEngine(power,capacity,gears);
}
ElectricEngine * HybridCar::changeEngine(int power, int battery)
{
    ElectricCar::changeEngine(power, battery);
}
