#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
    : ElectricCar(electricEng), PetrolCar(petrolEng) {
}

HybridCar::~HybridCar() {
}
void HybridCar::refill() {
    charge();
    refuel();
}
void HybridCar::changeEngine(Engine* engine) {
    PetrolCar::changeEngine(engine);
    ElectricCar::changeEngine(engine);
}

int HybridCar::getEnginePower() {
    return electricEngine_->getPower() + petrolEngine_->getPower();
}
