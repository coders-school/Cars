#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> secondEng)
    : PetrolCar(std::move(petrolEng)), ElectricCar(std::move(secondEng)) {}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::restore() {
    PetrolCar::restore();
    ElectricCar::restore();
}

void HybridCar::changeEngine(std::unique_ptr<PetrolEngine> newEngine) {
    PetrolCar::changeEngine(std::move(newEngine));
}

void HybridCar::changeEngine(std::unique_ptr<ElectricEngine> newEngine) {
    ElectricCar::changeEngine(std::move(newEngine));
}
