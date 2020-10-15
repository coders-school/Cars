#include "PetrolCar.hpp"
#include <iostream>
#include "InvalidEngine.hpp"


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
void PetrolCar::restore() {
    refuel();
}

void PetrolCar::changeGear(int gear) {
    engine_->changeGear(gear);
}

int PetrolCar::getGears() const {
    return engine_->getGears();
}

void PetrolCar::changeEngine(std::shared_ptr<PetrolEngine> engine) {
    std::cout << __FUNCTION__ << std::endl;
    if (getSpeed() != 0) {
        throw InvalidEngine("Car is in move. Cannot change engine during driving");
    } else {
        engine_ = engine;
    }
}

int PetrolCar::getPower() const {
    return engine_->getPower();
}

float PetrolCar::getCapacity() const {
    return engine_->getCapacity();
}

int PetrolCar::getCurrentGear() const{
    return engine_->getCurrentGear();
}
