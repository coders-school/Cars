#include <iostream>

#include "PetrolCar.hpp"

PetrolCar::PetrolCar(std::shared_ptr<PetrolEngine> engine)
    : engine_(engine)
{
    std::cout << "* " << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << "* " << __FUNCTION__ << std::endl;
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__;
    if (fuelLevel_ < MAX_CAPACITY) {
        fuelLevel_ = MAX_CAPACITY;
        std::cout << " : refuelled" << std::endl;
    } else {
        throw std::invalid_argument("tank already full");
    }
}

size_t PetrolCar::getFuelLevel() {
    return fuelLevel_;
}

void PetrolCar::setEngine(std::shared_ptr<PetrolEngine> engine) {
    std::cout << __FUNCTION__;
    if (getSpeed() == 0) {
        std::cout << " : petrol engine changed" << std::endl;
        engine_ = engine;
        std::cout << "@ petrol power: " << engine_->getPower() << std::endl;
    } else {
        throw std::invalid_argument("(petrol) not possible unless stopped");
    }
}

void PetrolCar::restore() {
    refuel();
}

void PetrolCar::changeGear(int gear) {
    std::cout << __FUNCTION__;
    if (gear >= REVERSE && gear <= engine_->getGears()) {
        if (getSpeed() > 0 && gear == REVERSE) {
            std::cout << " : first stop to reverse" << std::endl;
        } else {
            engine_->changeGear(gear);
            if (gear == REVERSE) {
                std::cout << " : reverse" << std::endl;    
            } else {
                std::cout << " : " << gear << std::endl;
            }
        }        
    } else {
        throw std::invalid_argument("invalid gear");
    }
}
