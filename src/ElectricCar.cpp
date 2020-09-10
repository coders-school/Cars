#include "ElectricCar.hpp"
#include "MovingCar.hpp"
#include "InvalidEngine.hpp"

#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : electricEngine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
    delete electricEngine_;
}

void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::restore() {
    std::cout << __FUNCTION__ << std::endl;
    charge();
}

void ElectricCar::changeEngine(Engine* engine) {
    if (speed_ != 0) {
        throw MovingCar("Car is in move");
    } else if (typeid(*engine) == typeid(ElectricEngine)) {
        delete electricEngine_;
        electricEngine_ = static_cast<ElectricEngine*>(engine);
    } else {
        throw InvalidEngine("Invalid engine type");
    }
}
