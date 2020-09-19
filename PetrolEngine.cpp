#include "PetrolEngine.hpp"

#include <cmath>
#include <iostream>

#include "Exceptions.hpp"

PetrolEngine::PetrolEngine(int power, float capacity, int gears) : Engine(power) {
    std::cout << __FUNCTION__ << std::endl;
    if (capacity <= 0) {
        throw InvalidParameter("Capacity cannot be lower or equal to zero.\n");
    } else if (gears <= 0) {
        throw InvalidParameter("Number of gears cannot be lower or equal to zero.\n");
    }
    capacity_ = capacity;
    gears_ = gears;
    currentGear_ = 0;
}

void PetrolEngine::changeGear(int gear) {
    if (gear > gears_ || gear < -1) {
        throw InvalidGear("You want to set incorrect gear.");
    } else if (gear == -1 && currentGear_ > 0) {
        throw InvalidGear("It is very hard to change gear to R now, please do not try it.");
    } else if (std::abs(currentGear_ - gear) > 2) {
        throw InvalidGear("Difference between gears is too big");
    }

    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}

int PetrolEngine::getPower() {
    return power_;
}

float PetrolEngine::getCapacity() {
    return capacity_;
}

int PetrolEngine::getGears() {
    return gears_;
}

int PetrolEngine::getCurrentGear() {
    return currentGear_;
}
