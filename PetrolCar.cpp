#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine)) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::changeEngine(std::unique_ptr<PetrolEngine> engine) {
    if(this->getSpeed() == 0) {
        engine_ = std::move(engine);
    }
    else {
        std::cout<<"You cannot change engine while driving!!!";
    };
}