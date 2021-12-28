#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* electricEngine)
    : electricEngine_(electricEngine) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::changeEngine(ElectricEngine* electricEngine) {
    std::cout << __FUNCTION__ << std::endl;
    delete electricEngine_;
    electricEngine_ = electricEngine;
}

void ElectricCar::refill() {
    charge();
}
