#include <iostream>

#include "PetrolCar.hpp"

PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine)
{
    std::cout << "* " << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << "* " << __FUNCTION__ << std::endl;
    delete engine_;
}

void PetrolCar::refuel() {
    std::cout << __FUNCTION__;
    if (fuelLevel_ < MAX_CAPACITY) {
        fuelLevel_ = MAX_CAPACITY;
        std::cout << " : refuelled" << std::endl;
    } else {
        std::cerr << " : tank already full" << std::endl;
    }
}

size_t PetrolCar::getFuelLevel() {
    return fuelLevel_;
}

void PetrolCar::setEngine(PetrolEngine* engine) {
    std::cout << __FUNCTION__;
    if (!getSpeed()) {
        std::cout << " : engine changed" << std::endl;
        delete engine_;
        engine_ = engine;
        std::cout << "@ petrol power: " << engine_->getPower() << std::endl;
    } else {
        delete engine;
        std::cout << " : not possible unless stopped" << std::endl;
    }
}
void PetrolCar::setEngine(ElectricEngine*) {}
void PetrolCar::setEngine(PetrolEngine*, ElectricEngine*) {}


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
