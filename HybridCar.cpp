#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng)
    : petrolEngine_(std::move(petrolEng)), electricEngine_(std::move(electricEng)) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::powerSuply() {
    charge();
    refuel();
}

void HybridCar::changeEngine(int power, float capacity, int gears, int pow, int bat_capacity) {
    petrolEngine_ = std::make_unique<PetrolEngine>(power, capacity, gears);
    electricEngine_ = std::make_unique<ElectricEngine>(pow, bat_capacity);
}
const std::unique_ptr<ElectricEngine>& HybridCar::getElectricEngine() {
    return electricEngine_;
}
const std::unique_ptr<PetrolEngine>& HybridCar::getPetrolEngine() {
    return petrolEngine_;
}