#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEngine, std::unique_ptr<ElectricEngine> electricEngine)
    : ElectricCar(std::move(electricEngine)), PetrolCar(std::move(petrolEngine)) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::refill() {
    ElectricCar::refill();
    PetrolCar::refill();
}
