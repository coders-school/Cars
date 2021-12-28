#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(PetrolEngine* petrolEngine)
    : petrolEngine_(petrolEngine) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::changeEngine(PetrolEngine* petrolEngine) {
    std::cout << __FUNCTION__ << std::endl;
    delete petrolEngine_;
    petrolEngine_ = petrolEngine;
}

void PetrolCar::refill() {
    refuel();
}

void PetrolCar::changeGear(int gear) {
    petrolEngine_->changeGear(gear);
}
