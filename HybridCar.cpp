#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
    : PetrolCar(petrolEng)
    , ElectricCar(electricEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar()       { std::cout << __FUNCTION__ << std::endl; }

void HybridCar::refill() {  
    ElectricCar::refill();
    PetrolCar::refill();
}

void HybridCar::changeEngine(ElectricEngine* engine) {
    ElectricCar::changeEngine(engine);
}

void HybridCar::changeEngine(PetrolEngine* engine) {
    PetrolCar::changeEngine(engine);
}
