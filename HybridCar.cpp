#include "HybridCar.hpp"

#include <iostream>

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEngine, std::unique_ptr<ElectricEngine> electricEngine)
    : PetrolCar(std::move(petrolEngine)), ElectricCar(std::move(electricEngine)) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::restore() {
    ElectricCar::restore();
    PetrolCar::restore();
}

void HybridCar::changeEngine(std::unique_ptr<ElectricEngine> electricEngine,
                             std::unique_ptr<PetrolEngine> petrolEngine) {
    PetrolCar::changeEngine(std::move(petrolEngine));
    ElectricCar::changeEngine(std::move(electricEngine));
}
