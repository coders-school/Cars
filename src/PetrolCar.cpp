#include "PetrolCar.hpp"
#include "MovingCar.hpp"
#include "InvalidEngine.hpp"

#include <iostream>
 
PetrolCar::PetrolCar(PetrolEngine* engine)
    : petrolEngine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
    delete petrolEngine_;
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::restore() {
    std::cout << __FUNCTION__ << std::endl;
    refuel();
}

void PetrolCar::changeEngine(Engine* engine) {
    if (speed_ != 0) {
        throw MovingCar("Car is in move");
    } else if (typeid(*engine) == typeid(PetrolEngine)) {
        delete petrolEngine_;
        petrolEngine_ = static_cast<PetrolEngine*>(engine);
    } else {
        throw InvalidEngine("Invalid engine type");
    }
}
