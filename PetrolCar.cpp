#include "PetrolCar.hpp"

#include <iostream>

#include "InvalidEngineChange.hpp"
#include "InvalidGear.hpp"

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine))
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()         { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::restore() {
    refuel();
}

void PetrolCar::changeGear(int gear) {
    if (gear == -1 && speed_ > 0) {
        throw InvalidGear("> cannot put in reverese gear while driving");
    }
    engine_->changeGear(gear);
}

int PetrolCar::getCurrentGear() {
    return engine_->getCurrentGear();
}

void PetrolCar::changeEngine(std::unique_ptr<PetrolEngine> engine) {
    if (speed_ > 0) {
        throw InvalidEngineChange("> cannot change engine while driving!");
    }
    std::swap(engine_, engine);
}
