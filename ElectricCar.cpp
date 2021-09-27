#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : electricEngine_(std::move(engine)) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::powerSuply() {
    charge();
}

void ElectricCar::changeEngine(int power, float bat_capacity, int p, int c, int g) {
    electricEngine_ = std::make_unique<ElectricEngine>(power, static_cast<int>(bat_capacity));
}

const std::unique_ptr<ElectricEngine>& ElectricCar::getElectricEngine() {
    return electricEngine_;
}
