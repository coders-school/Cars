#include "PetrolCar.hpp"
#include <iostream>

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

void PetrolCar::printInfoEngine() const {
    engine_->printInfoEngine();
}

int PetrolCar::getGear() {
    return engine_->getCurrentGear();
}

void PetrolCar::showGear() {
    engine_->showCurrentGear();
}

void PetrolCar::setGear(int gear) {
    engine_->changeGear(gear);
}

void PetrolCar::changeEngine(std::unique_ptr<PetrolEngine> engine) {
    if (speed_ == 0) {
        std::swap(engine_, engine);
    } else {
        throw InvalidEngine("Can not change the engine during a drive !");
    }
}