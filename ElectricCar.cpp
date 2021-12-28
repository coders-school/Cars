#include "ElectricCar.hpp"
#include <iostream>
#include <memory>

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> electricEngine)
    : electricEngine_(std::move(electricEngine)) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::changeEngine(std::unique_ptr<ElectricEngine> electricEngine) {
    std::cout << __FUNCTION__ << std::endl;
    electricEngine_ = std::move(electricEngine);
}

void ElectricCar::refill() {
    charge();
}
