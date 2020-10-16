#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng)
    : PetrolCar(std::move(petrolEng)), ElectricCar(std::move(electricEng)) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::restore() {
    PetrolCar::restore();
    ElectricCar::restore();
}

void HybridCar::printInfoEngine() const {
    PetrolCar::printInfoEngine();
    ElectricCar::printInfoEngine();
}

void HybridCar::changePetrolEngine(std::unique_ptr<PetrolEngine> petrolEngine) {
    PetrolCar::changeEngine(std::move(petrolEngine));
}

void HybridCar::changeElectricEngine(std::unique_ptr<ElectricEngine> electricEngine) {
    ElectricCar::changeEngine(std::move(electricEngine));
}