#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine))
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()         { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::changeGear(int gear) {
    engine_->changeGear(gear);
}
void PetrolCar::changeEngine(std::unique_ptr<PetrolEngine> petrolEngine) {
    if(this->getSpeed() != 0.0) {
        engine_ = std::move(petrolEngine);
        return;
    }
    throw Car::CarMoving{"Can't change an engine when car is moving!"};
}

void PetrolCar::refill() {
    refuel();
}
