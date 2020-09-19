#include "ElectricCar.hpp"

#include <iostream>

#include "Exceptions.hpp"

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
    if (this->getSpeed() == 0) {
        std::swap(engine_, engine);
        std::cout << "Changed electric engine\n";
    } else {
        throw InvalidEngineChange("Can't change engine during driving\n");
    }
}

int ElectricCar::getPower() {
    return engine_->getPower();
}

int ElectricCar::getBatteryCapacity() {
    return engine_->getBatteryCapacity();
}
