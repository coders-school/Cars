#include "ElectricCar.hpp"

#include <iostream>

#include "exception/InvalidEngineChange.hpp"

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : engine_(std::move(engine))
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar()       { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::restore() {
    charge();
}

void ElectricCar::changeEngine(std::unique_ptr<ElectricEngine>  engine) {
    if (speed_ > 0) {
        throw InvalidEngineChange("> cannot change engine while driving!");
    }
    std::swap(engine_, engine);
}
