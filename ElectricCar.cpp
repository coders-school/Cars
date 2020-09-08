#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    delete engine_;
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::restore()       { charge(); }
void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::setEngine(int power, int batteryCapacity) {
    if (Car::speed_ == 0) {
        engine_ = new ElectricEngine(power, batteryCapacity);
        std::cout << "Engine changed" << std::endl;
    }
    else {
        std::cout << "Can't change engine while driving (please verify with Youtube)" <<std::endl;
    }
}

int ElectricCar::getEnginePower() {
    return engine_->getPower();
}

