#include "ElectricCar.hpp"

#include <iostream>

#include "InvalidEngineChange.hpp"

ElectricCar::ElectricCar(ElectricEngine* electricEngine)
    : electricEngine_(electricEngine) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    delete electricEngine_;
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::restore() {
    charge();
}

void ElectricCar::carInfo() {
    std::cout << "Car info:\n "
              << "Speed: " << getSpeed() << '\n'
              << "Power: " << getEnginePower() << '\n'
              << "Battery Capacity: " << electricEngine_->getBatteryCapacity() << '\n';
}

uint16_t ElectricCar::getEnginePower() const {
    return electricEngine_->getPower();
}

void ElectricCar::changeEngine(Engine* engine) {
    if (getSpeed() != MINIMUM_VELOCITY) {
        throw InvalidEngineChange("You can't change engine while driving!");
    }

    if (typeid(*engine) != typeid(ElectricEngine)) {
        throw InvalidEngineChange("Wrong engine!");
    }

    delete electricEngine_;
    electricEngine_ = static_cast<ElectricEngine*>(engine);
}
