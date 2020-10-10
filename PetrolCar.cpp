#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine) {}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
    delete engine_;
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::restore() {
    refuel();
}
