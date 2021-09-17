#include "PetrolEngine.hpp"
#include <iostream>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear) {
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}

int PetrolEngine::getPower() {
    return power_;
}

int PetrolEngine::getCapacity() {
    return capacity_;
}

int PetrolEngine::getGears() {
    return gears_;
}

int PetrolEngine::getCurrentGear() {
    return currentGear_;
}

void PetrolEngine::setPower(int power) {
    power_ = power;
}

void PetrolEngine::setCapacity(float capacity) {
    capacity_ = capacity;
}

void PetrolEngine::setGears(int gears) {
    gears_ = gears;
}

void PetrolEngine::setCurrentGear(int currentGear) {
    currentGear_ = currentGear;
}