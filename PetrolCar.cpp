#include "PetrolCar.hpp"

#include <iostream>

#include "Exception.hpp"

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine)) {}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::restore() {
    refuel();
}

void PetrolCar::changeEngine(std::unique_ptr<PetrolEngine> newEngine) {
    if (getSpeed() == 0) {
        engine_.swap(newEngine);
    } else {
        throw InvalidEngineChange("Changing engine while driving is not safe.");
    }
}
