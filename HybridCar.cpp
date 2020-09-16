#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng)
    :  ElectricCar(std::move(electricEng)),
       PetrolCar(std::move(petrolEng))
    
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar()       { std::cout << __FUNCTION__ << std::endl; }

 
void HybridCar::restore() {
    
}
