#include "PetrolEngine.hpp"
#include <iostream>
#include "InvalidGear.hpp"

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear) {
    if (gear > gears_ || gear < -1) {
        throw InvalidGear("Gearbox out of range!");
    }
    if (gear == -1 && currentGear_ >= 2) {
        throw InvalidGear("Gearbox cannot change gear to R from such a high gear");
    }
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}

float PetrolEngine::getCapacity() const {
    return capacity_;
}

int PetrolEngine::getGears() const {
    return gears_;
}

int PetrolEngine::getCurrentGear() const {
    return currentGear_;
}

int PetrolEngine::getPower() const {
    return power_;
}
