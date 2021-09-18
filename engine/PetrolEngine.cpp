#include "PetrolEngine.hpp"

#include <iostream>

#include "../exception/InvalidGear.hpp"

constexpr int reverse_gear{ -1 };

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : Engine(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear)
{
    if (gear > gears_ || gear < reverse_gear) {
        throw InvalidGear("> no such gear!");
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
