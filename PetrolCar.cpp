#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::restore() {
    refuel();
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

int PetrolCar::getGear() const {
    return this->engine_->getCurrentGear();
}

void PetrolCar::setGear(int newGear) {
    this->engine_->changeGear(newGear);
}
