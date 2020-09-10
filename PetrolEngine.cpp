#include "PetrolEngine.hpp"

#include <iostream>

#include "InvalidGear.hpp"

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : Engine(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear) {
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    if (gear > gears_ || gear < -1) {
        throw InvalidGear("You want to set incorrect gear.");
    } else if (gear == -1 && currentGear_ > 0) {
        throw InvalidGear("It is very hard to change gear to R now, please do not try it.");
    }

    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
