#include "ElectricCar.hpp"
#include <iostream>
#include "CarInMovementExcept.hpp"

ElectricCar::ElectricCar(ElectricEngine* engine)
    : electricEngine_(engine) {
}

ElectricCar::~ElectricCar() {
}
void ElectricCar::refill() {
    charge();
}
void ElectricCar::charge() {
}

void ElectricCar::changeEngine(Engine* electricEngine) {
    if (currentSpeed_ != 0) {
        throw CarInMovementExcept("Car is moving");
    } else if (typeid(*electricEngine) == typeid(ElectricEngine)) {
        delete electricEngine_;
        electricEngine_ = static_cast<ElectricEngine*>(electricEngine);
    }
}

int ElectricCar::getEnginePower() {
    return electricEngine_->getPower();
}
