#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(PetrolEngine *engine)
        : engine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::refuel() { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::feed() { refuel(); }

void PetrolCar::setEngine(Engine *e) {
    engine_ = dynamic_cast<PetrolEngine*>(e);
}


