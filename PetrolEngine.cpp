#include <iostream>

#include "PetrolEngine.hpp"

constexpr int neutralGear = 0;
constexpr int reverseGear = 0;

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear) {
    if (gear == reverseGear && currentGear_ != neutralGear) {
        throw InvalidGearException("Cannot shift gear into reverse having positive one");
    }

    if (gear > gears_) {
        throw InvalidGearException("You are passing invalid gear, your engine is limited to " + gears_ + " gears");
    }

    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
