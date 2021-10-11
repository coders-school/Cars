#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : engine_(std::move(engine)), charge_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::charge() {
    charge_ = 100;
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::changeEngine(std::unique_ptr<ElectricEngine> engine)  { 
    if(this->getSpeed() > 0) {
        throw Car::CarMoving("It is impossible to change the engine while car is moving!!!");
    }
    engine_ = std::move(engine);
}
