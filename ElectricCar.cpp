#include <iostream>

#include "ElectricCar.hpp"

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : engine_(std::move(engine)){
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::restore() {
    charge();
}

void ElectricCar::changeEngine(std::unique_ptr<ElectricEngine> engine) {
    if (getSpeed() != 0) {
        throw InvalidEngineChange("Can't change engine while it is running");
    }
    engine_ = std::move(engine);
}
