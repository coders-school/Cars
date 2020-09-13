#include "ElectricCar.hpp"

#include <iostream>

#include "WrongEngine.hpp"
#include "CarHaveMove.hpp"

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
            throw InvalidEngine("Wrong type of Engine");
            return;
        }

        delete electricEngine_;
        electricEngine_ = static_cast<ElectricEngine*>(engine);
        std::cout << "Changed electric engine\n";
    }else {
        throw MovingCar("Can you switch your Engine while u driving? Respect+");
    }
}