#include "PetrolEngine.hpp"
#include <iostream>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : Engine(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear) {
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    std::cout << __FUNCTION__ << std::endl;

    if (-1 > gear || gears_ < gear) {
        throw InvalidGear("Non existant gear");
    }
    currentGear_ = gear;
}

int PetrolEngine::getCurrentGear() {
    return currentGear_;
}