#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
    : ElectricCar(electricEng)
    , PetrolCar(petrolEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar()       { std::cout << __FUNCTION__ << std::endl; }


void HybridCar::refill() {
    ElectricCar::refill();
    PetrolCar::refill();
}

void HybridCar::changeEngine(PetrolEngine* petrolEngineNew, ElectricEngine* electroEngineNew) {
    PetrolCar::changeEngine(petrolEngineNew);
    ElectricCar::changeEngine(electroEngineNew);
}

// void HybridCar::changeEngine(ElectricEngine* electricEngineNew) {
//     delete electricEngine_;
//     electricEngine_ = electricEngineNew;
// }
 

