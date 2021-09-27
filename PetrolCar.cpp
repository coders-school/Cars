#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : petrolEngine_(std::move(engine)) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::powerSuply() {
    refuel();
}

void PetrolCar::changeEngine(int power, float capacity, int gears, int p, int bc) {
    petrolEngine_ = std::make_unique<PetrolEngine>(power, capacity, gears);
}

const std::unique_ptr<PetrolEngine>& PetrolCar::getPetrolEngine() {
    return petrolEngine_;
}