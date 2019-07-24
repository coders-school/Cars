#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine *petrolEng, ElectricEngine *electricEng)
    : PetrolCar(petrolEng), ElectricCar(electricEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() { std::cout << __FUNCTION__ << std::endl; }

void HybridCar:: addEnergy() {
    if(PetrolCar::petrolCondition < 20){
        PetrolCar::addEnergy();
    }else if(ElectricCar::electricCondition < 20){
        ElectricCar::addEnergy();
    }
}

