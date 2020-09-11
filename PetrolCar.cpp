#include "PetrolCar.hpp"

#include <iostream>

PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::restore() {
    refuel();
}

void PetrolCar::changeGear(int gear) try {
    engine_->setCurrentGear(gear);
} catch (const std::logic_error& error) {
    std::cout << error.what() << '\n';
}
