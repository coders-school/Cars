#include "PetrolEngine.hpp"
#include <iostream>
#include "InvalidGear.hpp"
#include <stdexcept>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear) {
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    if (gear == -1 && currentGear_ != 0 || currentGear_ > gears_ || currentGear_ < -1) {
        throw InvalidGear("Never change to reverse gear from farward gear!!");
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}

int PetrolEngine::getGears() const {
    return gears_;
}

int PetrolEngine::getPower() const {
    return power_;
}

float PetrolEngine::getCapacity() const {
    return capacity_;
}

int PetrolEngine::getCurrentGear() const {
    return capacity_;
}
