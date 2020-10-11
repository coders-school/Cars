#include "ElectricCar.hpp"

#include <iostream>

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
