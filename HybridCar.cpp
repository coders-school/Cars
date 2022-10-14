#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
        : ElectricCar(electricEng), PetrolCar(petrolEng) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() { std::cout << __FUNCTION__ << std::endl; }

void HybridCar::refill() {
    ElectricCar::refill();
    PetrolCar::refill();
}