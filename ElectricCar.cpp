#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine) : engine_(std::move(engine)) {
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
    if (speed_ == 0) {
        engine_ = std::move(engine);
    } else {
        throw InvalidEngine("Can not change the engine during a drive !");
    }
}

void ElectricCar::getInfoEngine() {
    engine_->getInfoEngine();
}