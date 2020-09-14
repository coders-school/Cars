#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(PetrolEngine* engine)
    : petrolEngine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    delete petrolEngine_;
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::restore() {
    refuel();
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::setGear(int newGear) {
    this->petrolEngine_->changeGear(newGear);
}

void PetrolCar::changeEngine(Engine* engine) {
    std::cout << __FUNCTION__ << std::endl;
    if (currentSpeed_ != 0) {
        std::cout << "Changing of engine during driving is not possible!" << std::endl;
        return;
    }
    if (typeid(*engine) != typeid(PetrolEngine)) {
        std::cout << "Engine can be changed only fo PETROL type engine" << std::endl;
        return;
    }
    delete petrolEngine_;
    petrolEngine_ = static_cast<PetrolEngine*>(engine);
}

int PetrolCar::getGear() const {
    return this->petrolEngine_->getCurrentGear();
}

int PetrolCar::getPetrolEnginePower() const {
    return this->petrolEngine_->getPower();
}
float PetrolCar::getPetrolEngineCapacity() const {
    return this->petrolEngine_->getCapacity();
}
