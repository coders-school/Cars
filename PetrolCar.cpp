#include "PetrolCar.hpp"
#include "ExceptionsClass.hpp"
#include <iostream>

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : petrolEngine_(std::move(engine)) {
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

void PetrolCar::changeGear(GearBox gear) {
    petrolEngine_->setGear(gear);
}

std::unique_ptr<PetrolEngine> PetrolCar::changeEngine(std::unique_ptr<PetrolEngine> newEngine) {
    if (speed_ != 0) {
        throw InvalidChangeEngine("You have to stop the car if you would like change engine");
    }
    std::unique_ptr<PetrolEngine> tmp;
    tmp = std::move(newEngine);
    std::swap(tmp, petrolEngine_);
    return tmp;
}
