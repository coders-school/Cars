#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : engine_(std::move(engine))
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar()       { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::changeEngine(std::unique_ptr<ElectricEngine> electricEngine) {
    if(this->getSpeed() != 0.0) {
        engine_ = std::move(electricEngine);
        return;
    }
    throw Car::CarMoving{"Can't change an engine when car is moving!"};
}
void ElectricCar::refill() {
    charge();
}
