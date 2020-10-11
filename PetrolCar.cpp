#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    delete engine_;
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::restore() {
    refuel();
}

void PetrolCar::changeGear(int gear) {
    engine_->changeGear(gear);
}

int PetrolCar::getGear() const {
    return engine_->getGear();
}
