#include "PetrolCar.hpp"

#include <iostream>

#include "Exceptions.hpp"

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine) : engine_(std::move(engine)) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::restore() {
    refuel();
}

void PetrolCar::changeEngine(std::unique_ptr<PetrolEngine> engine) {
    if (this->getSpeed() == 0) {
        std::swap(engine_, engine);
        std::cout << "Changed petrol engine\n";
    } else {
        throw InvalidEngineChange("Can't change engine during driving\n");
    }
}

void PetrolCar::setGear(int gear) {
    engine_->changeGear(gear);
}

int PetrolCar::getCurrentGear() {
    return engine_->getCurrentGear();
}

int PetrolCar::getPower() {
    return engine_->getPower();
}

float PetrolCar::getCapacity() {
    return engine_->getCapacity();
}

int PetrolCar::getGears() {
    return engine_->getGears();
}
