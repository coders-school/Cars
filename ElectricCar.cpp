#include "ElectricCar.hpp"

#include <iostream>

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

void ElectricCar::changeEngine(Engine* engine) {
    if (getSpeed() != MINIMUM_VELOCITY) {
        std::cout << "You can't change engine while driving!\n";
        return;
    }

    if (typeid(*engine) != typeid(ElectricEngine)) {
        std::cout << "Wrong engine!\n";
        return;
    }

    delete electricEngine_;
    electricEngine_ = static_cast<ElectricEngine*>(engine);
    std::cout << __FUNCTION__ << std::endl;
}