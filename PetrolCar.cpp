#include "PetrolCar.hpp"
#include <iostream>
#include "CarInMovementExcept.hpp"

PetrolCar::PetrolCar(PetrolEngine* engine)
    : petrolEngine_(engine) {
}

PetrolCar::~PetrolCar() {
}
void PetrolCar::refill() {
    refuel();
}
void PetrolCar::refuel() {
}

void PetrolCar::changeEngine(Engine* petrolEngine) {

    if (currentSpeed_ != 0) {
        throw CarInMovementExcept("Car is moving");
    }
    else if (typeid(*petrolEngine) == typeid(PetrolEngine)) {
        delete petrolEngine_;
        petrolEngine_ = static_cast<PetrolEngine*>(petrolEngine);
    }
}

void PetrolCar::changeGear(int gear) {
    petrolEngine_->changeGear(gear);
}

int PetrolCar::getEnginePower() {
    return petrolEngine_->getPower();
}

int PetrolCar::getCurrentGear() {
    return petrolEngine_->getCurrentGear();
}