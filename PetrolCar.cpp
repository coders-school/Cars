#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(std::shared_ptr<PetrolEngine> engine)
    : engine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::changeEngine(std::shared_ptr<PetrolEngine> newEngine) {
    engine_ = newEngine;
}
void PetrolCar::refill() {
    refuel();
}

void PetrolCar::changeGear(int newGear) {
    engine_->changeGear(newGear);
}
