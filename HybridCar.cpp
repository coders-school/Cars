#include "HybridCar.hpp"
#include <iostream>
#include <utility>

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng, ElectricEngine* electricEng)
    : PetrolCar(std::move(petrolEng))
    , ElectricCar(electricEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar()       { std::cout << __FUNCTION__ << std::endl; }


void HybridCar::refill() {
    ElectricCar::refill();
    PetrolCar::refill();
}

void HybridCar::changeEngine(std::unique_ptr<PetrolEngine> petrolEngineNew, ElectricEngine* electroEngineNew) {
    PetrolCar::changeEngine(std::move(petrolEngineNew));
    ElectricCar::changeEngine(electroEngineNew);
}

// void HybridCar::changeEngine(ElectricEngine* electricEngineNew) {
//     delete electricEngine_;
//     electricEngine_ = electricEngineNew;
// }
 

