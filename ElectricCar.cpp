#include "ElectricCar.hpp"

#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : electricEngine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
    delete electricEngine_;
}

void ElectricCar::restore() {
    std::cout << __FUNCTION__ << std::endl;
    charge();
}

void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}

int ElectricCar::getBatteryCapacity() const {
    return electricEngine_->getBatteryCapacity();
}

int ElectricCar::getElectricPower() const {
    return electricEngine_->getPower();
}

void ElectricCar::changeEngine(Engine* engine) {
    if (speed_ == 0) {
        if (typeid(*engine) != typeid(ElectricEngine)) {
            std::cout << "Wrong type of engine\n";
            return;
        }

        delete electricEngine_;
        electricEngine_ = static_cast<ElectricEngine*>(engine);
        std::cout << "Changed electric engine\n";
    } else {
        std::cout << "Can't change engine during driving\n";
    }
}
