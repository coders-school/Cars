#include "HybridCar.hpp"
#include <iostream>
#include <memory>
#include <utility>
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

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

void HybridCar::changeEngine(std::unique_ptr<PetrolEngine> engine) {
    PetrolCar::changeEngine(std::move(engine));
}
void HybridCar::changeEngine(std::unique_ptr<ElectricEngine> engine) {
    ElectricCar::changeEngine(std::move(engine));
}
