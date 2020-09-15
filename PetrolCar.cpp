#include "PetrolCar.hpp"

#include <iostream>

#include "InvalidEngineChange.hpp"

PetrolCar::PetrolCar(PetrolEngine* petrolEngine)
    : petrolEngine_(petrolEngine) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    delete petrolEngine_;
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::restore() {
    refuel();
}

void PetrolCar::carInfo() {
    std::cout << "Car info: \n "
              << "Speed: " << getSpeed() << '\n'
              << "Power: " << getEnginePower() << '\n'
              << "Capacity: " << petrolEngine_->getCapacity() << '\n'
              << "Current Gear: " << petrolEngine_->getCurrentGear() << '\n'
              << "Gears: " << unsigned(petrolEngine_->getGears()) << '\n';
}

uint16_t PetrolCar::getEnginePower() const {
    return petrolEngine_->getPower();
}

void PetrolCar::changeGear(int gear) {
    petrolEngine_->setCurrentGear(gear);
}

void PetrolCar::changeEngine(Engine* engine) {
    if (getSpeed() != MINIMUM_VELOCITY) {
        throw InvalidEngineChange("You can't change engine while driving!");
    }
    if (typeid(*engine) != typeid(PetrolEngine)) {
        throw InvalidEngineChange("Wrong engine!");
    }
    delete petrolEngine_;
    petrolEngine_ = static_cast<PetrolEngine*>(engine);
}

int PetrolCar::getCurrentGear() const {
    return petrolEngine_->getCurrentGear();
}