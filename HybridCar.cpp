#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng)
    : petrolEngine_(std::move(petrolEng)), electricEngine_(std::move(electricEng)) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::turnLeft() {
    std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::turnRight() {
    std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::brake() {
    std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::accelerate(int) {
    std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

const std::unique_ptr<ElectricEngine>& HybridCar::getElectricEngine() {
    return electricEngine_;
}
const std::unique_ptr<PetrolEngine>& HybridCar::getPetrolEngine() {
    return petrolEngine_;
}
