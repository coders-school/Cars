#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEngine, ElectricEngine* electricEngine)
    : ElectricCar(electricEngine), PetrolCar(petrolEngine) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::refill() {
    ElectricCar::refill();
    PetrolCar::refill();
}
