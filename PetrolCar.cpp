#include "PetrolCar.hpp"

#include <iostream>

#include "WrongEngine.hpp"
#include "CarHaveMove.hpp"

PetrolCar::PetrolCar(PetrolEngine* engine)
    : petrolEngine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
    delete petrolEngine_;
}

void PetrolCar::changeGear(int gear) {
    petrolEngine_->setCurrentGear(gear);
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::restore() {
    std::cout << __FUNCTION__ << std::endl;
    refuel();
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::changeEngine(Engine* engine) {
    if (speed_ == 0) {
        if (typeid(*engine) != typeid(PetrolEngine)) {
            throw InvalidEngine("Wrong type of Engine");
            return;
        }

        delete petrolEngine_;
        petrolEngine_ = dynamic_cast<PetrolEngine*>(engine);
        std::cout << "Changed petrol engine\n";
    } else {
        throw MovingCar("Can you switch your Engine while u driving? Respect+");
    }
}

int PetrolCar::getCurrentGear() const {
    return petrolEngine_->getCurrentGear();
}

int PetrolCar::getPetrolPower() const {
    return petrolEngine_->getPower();
}