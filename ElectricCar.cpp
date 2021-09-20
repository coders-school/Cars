#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : electricEngine_(std::move(engine)) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::turnLeft() {
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::turnRight() {
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::brake() {
    std::cout << "brake electric car \n" << std::endl;
}
void ElectricCar::accelerate(int) {
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}

const std::unique_ptr<ElectricEngine>& ElectricCar::getElectricEngine() {
    return electricEngine_;
}