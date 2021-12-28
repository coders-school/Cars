#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> petrolEngine)
    : petrolEngine_(std::move(petrolEngine)) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::changeEngine(std::unique_ptr<PetrolEngine> petrolEngine) {
    std::cout << __FUNCTION__ << std::endl;
    petrolEngine_ = std::move(petrolEngine);
}

void PetrolCar::refill() {
    refuel();
}

void PetrolCar::changeGear(int gear) {
    petrolEngine_->changeGear(gear);
}
