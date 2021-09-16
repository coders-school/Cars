#include "PetrolCar.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
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

void PetrolCar::changeEngine(std::unique_ptr<PetrolEngine> engine) {
    std::cout << __FUNCTION__ << std::endl;
    engine_.reset();
    engine_ = std::move(engine);
    engine_->attach(this);
}
void PetrolCar::changeEngine(std::unique_ptr<ElectricEngine>) {
    throw std::invalid_argument("Cannot change electric engine in petrol car");
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}
