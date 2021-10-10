#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : engine_(std::move(engine)) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::changeEngine(std::unique_ptr<ElectricEngine> engine)  { 
    if(this->getSpeed() == 0) {
        engine_ = std::move(engine);
    }
    else {
        std::cout<<"You cannot change engine while driving!!!";
    };
}