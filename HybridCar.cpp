#include "HybridCar.hpp"
#include <iostream>
#include <utility>

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng)
    : PetrolCar(std::move(petrolEng)), ElectricCar(std::move(electricEng)) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::refill() {
    PetrolCar::refill();
    ElectricCar::refill();
}

void HybridCar::changeEngine(std::unique_ptr<PetrolEngine> petrolEngineNew) {
    PetrolCar::changeEngine(std::move(petrolEngineNew));
}

void HybridCar::changeEngine(std::unique_ptr<ElectricEngine> electricEngineNew) {
    ElectricCar::changeEngine(std::move(electricEngineNew));
}
