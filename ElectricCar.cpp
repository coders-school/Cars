#include "ElectricCar.hpp"
#include <iostream>
#include "InvalidEngine.hpp"

ElectricCar::ElectricCar(std::shared_ptr<ElectricEngine> engine)
    : engine_(engine) {
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

void ElectricCar::changeEngine(std::shared_ptr<ElectricEngine> engine) {
    std::cout << __FUNCTION__ << std::endl;
    if (getSpeed() != 0) {
        throw InvalidEngine("Car is in move. Cannot change engine during driving");
    } else {
        engine_ = engine;
    }
}

int ElectricCar::getPower() const {
    return engine_->getPower();
}

int ElectricCar::getBatteryCapacity() const {
    return engine_->getBatteryCapacity();
}
