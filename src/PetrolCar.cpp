#include <iostream>

#include "PetrolCar.hpp"

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine)) {
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
    if (getSpeed() != 0) {
        throw InvalidEngineChange("Can't change engine while it is running");
    }
    engine_ = std::move(engine);
}
