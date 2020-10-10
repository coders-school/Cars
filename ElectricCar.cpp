#include "ElectricCar.hpp"

#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : engine_(engine) {}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
    delete engine_;
}

void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::restore() {
    charge();
}
