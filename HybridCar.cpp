#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* secondEng)
    : PetrolCar(petrolEng), ElectricCar(secondEng) {}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::restore() {
    PetrolCar::restore();
    ElectricCar::restore();
}
