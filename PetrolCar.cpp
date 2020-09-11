#include "PetrolCar.hpp"

#include <iostream>

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

void PetrolCar::changeGear(int gear) try {
    petrolEngine_->setCurrentGear(gear);
} catch (const std::logic_error& error) {
    std::cout << error.what() << '\n';
}

void PetrolCar::changeEngine(Engine* engine) {
    if (getSpeed() != MINIMUM_VELOCITY) {
        std::cout << "You can't change engine while driving!\n";
        return;
    }

    if (typeid(*engine) != typeid(PetrolEngine)) {
        std::cout << "Wrong engine!\n";
    }

    delete petrolEngine_;
    petrolEngine_ = static_cast<PetrolEngine*>(engine);
}