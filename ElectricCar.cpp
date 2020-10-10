#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(std::shared_ptr<ElectricEngine> engine)
    : engine_(engine)
{
    std::cout << "* " << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << "* " << __FUNCTION__ << std::endl;
}

void ElectricCar::charge() { 
    std::cout << __FUNCTION__;
    if (chargeLevel_ < MAX_CAPACITY) {
        chargeLevel_ = MAX_CAPACITY;
        std::cout << " : recharged" << std::endl;
    } else {
        throw std::invalid_argument("battery already full");
    }
}

size_t ElectricCar::getChargeLevel() {
    return chargeLevel_;
}

void ElectricCar::setEngine(std::shared_ptr<ElectricEngine> engine) {
    std::cout << __FUNCTION__;
    if (getSpeed() == 0) {
        std::cout << " : electric engine changed" << std::endl;
        engine_ = engine;
        std::cout << "@ electric power: " << engine_->getPower() << std::endl;
    } else {
        throw std::invalid_argument("(electric) not possible unless stopped");
    }
}

void ElectricCar::restore() {
    charge();
}

void ElectricCar::changeGear([[maybe_unused]] int gear) {
    std::cout << __FUNCTION__ << " : no transmission" << std::endl;
}
