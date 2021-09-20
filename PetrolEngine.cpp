#include "PetrolEngine.hpp"

#include <iostream>

#include "InvalidGear.hpp"
#include "InvalidParameter.hpp"

constexpr int reverse_gear{ -1 };

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : Engine(power)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
    if (capacity <= 0) {
        throw InvalidParameter("> capacity cannot be negative!");
    } else if(gears <= 0) {
        throw InvalidParameter("> gears cannot be negative!");
    }
    capacity_ = capacity;
    gears_ = gears;
}

void PetrolEngine::changeGear(int gear)
{
    if (gear > gears_ || gear < reverse_gear) {
        throw InvalidGear("> no such gear!");
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}

int PetrolEngine::getCurrentGear() {
    return currentGear_;
}
