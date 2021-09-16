#include "PetrolCar.hpp"
#include <iostream>
#include <memory>
#include <utility>
#include "PetrolEngine.hpp"

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine)) {
    engine_->attach(this);
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::refill() {
    this->refuel();
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}
