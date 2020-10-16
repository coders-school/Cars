#include "HybridCar.hpp"
#include <iostream>
#include "InvalidEngine.hpp"

HybridCar::HybridCar(std::shared_ptr<PetrolEngine> petrolEng, std::shared_ptr<ElectricEngine> electricEng)
    : PetrolCar(petrolEng), ElectricCar(electricEng) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::restore() {
    ElectricCar::restore();
    PetrolCar::restore();
}

void HybridCar::changeEngine(std::shared_ptr<ElectricEngine> electricEngine, std::shared_ptr<PetrolEngine> petrolEngine) {
    ElectricCar::changeEngine(electricEngine);
    PetrolCar::changeEngine(petrolEngine);
}

int HybridCar::getPower() const {
    return ElectricCar::getPower() + PetrolCar::getPower();
}
