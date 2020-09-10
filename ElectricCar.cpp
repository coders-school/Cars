#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : electricEngine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::refill() {
    std::cout << __FUNCTION__ << std::endl;
    charge();
}
void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::changeEngine(Engine* electricEngine) {
    std::cout << __FUNCTION__ << std::endl;

    if (typeid(*electricEngine) == typeid(ElectricEngine)) {
        delete electricEngine_;
        electricEngine_ = static_cast<ElectricEngine*>(electricEngine);
    }
}

int ElectricCar::getEnginePower() {
    return electricEngine_->getPower();
}