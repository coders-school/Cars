#include "ElectricCar.hpp"

#include <iostream>

#include "Exception.hpp"

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : engine_(std::move(engine)) {}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::restore() {
    charge();
}

void ElectricCar::changeEngine(std::unique_ptr<ElectricEngine> newEngine) {
    if (getSpeed() == noSpeed) {
        engine_.swap(newEngine);
    } else {
        throw InvalidEngineChange("Changing engine while driving is not safe.");
    }
}
