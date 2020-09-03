#include "PetrolEngine.hpp"

#include <iostream>

#include "InvalidGear.hpp"

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : Engine(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolEngine::~PetrolEngine() {
    std::cout << __FUNCTION__ << std::endl;
}

int PetrolEngine::getCurrentGear() const {
    return currentGear_;
}

int PetrolEngine::getGears() const {
    return gears_;
}

float PetrolEngine::getCapacity() const {
    return capacity_;
}

void PetrolEngine::setCurrentGear(int gear) {
    if (gear > gears_ || gear < -1) {
        throw InvalidGear("Gear out of range!!!");
    } else if (gear == -1 && currentGear_ >= 2) {
        throw InvalidGear("Cannot change gear to R from such a high gear!!!");
    }

    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
