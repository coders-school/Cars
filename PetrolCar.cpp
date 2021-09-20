#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine))
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::refuel() { 
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::changeGear(int gear) {
    engine_->changeGear(gear);
}