#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : engine_(engine)
{
    std::cout << "* " << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << "* " << __FUNCTION__ << std::endl;
    delete engine_;
}

void ElectricCar::charge() { 
    std::cout << __FUNCTION__;
    if (chargeLevel_ < MAX_CAPACITY) {
        chargeLevel_ = MAX_CAPACITY;
        std::cout << " : recharged" << std::endl;
    } else {
        std::cerr << " : battery already full" << std::endl;
    }
}

size_t ElectricCar::getChargeLevel() {
    return chargeLevel_;
}

void ElectricCar::setEngine(ElectricEngine* engine) {
    std::cout << __FUNCTION__;
    if (getSpeed() == 0) {
        std::cout << " : electric engine changed" << std::endl;
        delete engine_;
        engine_ = engine;
        std::cout << "@ electric power: " << engine_->getPower() << std::endl;
    } else {
        std::cout << " : (electric) not possible unless stopped" << std::endl;
    }
}

void ElectricCar::restore() {
    charge();
}

void ElectricCar::changeGear([[maybe_unused]] int gear) {
    std::cout << __FUNCTION__ << " : no transmission" << std::endl;
}
