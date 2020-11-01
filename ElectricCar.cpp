#include "ElectricCar.hpp"
#include "Exceptions.hpp"
#include <iostream>

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : electricEngine_(std::move(engine))
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar()       { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::restore() {
    charge();
}

void ElectricCar::changeElectricEngine(std::unique_ptr<ElectricEngine> newEngine) {
    if (speed_ != 0) {
        throw InvalidSpeed("Speed can't be different than zero, when you are changing the electric engine.");
    } else {
        std::swap(electricEngine_, newEngine);
    }
}