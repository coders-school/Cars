#include "PetrolEngine.hpp"
#include <cstdlib>
#include <iostream>

constexpr int BOTTOM_GEAR = -1;

InvalidGear::InvalidGear(const std::string& eWhat)
    : std::logic_error(eWhat)
{}

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolEngine::~PetrolEngine() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear)
{
    if (gear < BOTTOM_GEAR) {
        throw InvalidGear("Wrong gear");
    }
    else if (abs(gear - gears_) > 2) {
        throw InvalidGear("Too fast gear changing");
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
