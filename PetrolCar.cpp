#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine)), fuel_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::refuel() {
    fuel_ = 100;
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::changeEngine(std::unique_ptr<PetrolEngine> engine) {
    if(this->getSpeed() > 0) {
        throw Car::CarMoving("It is impossible to change the engine while car is moving!!!");
    }
    engine_ = std::move(engine);
}