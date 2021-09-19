#include "PetrolCar.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>
#include "MyExceptions.hpp"
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
    if (!engine) {
        throw InvalidEngine("Invalid engine provided to PetrolCar::changeEngine");
    }
    engine_->detach();  // Redundant for now
    engine_.reset();
    engine_ = std::move(engine);
    engine_->attach(this);
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}
