#include "PetrolEngine.hpp"
#include <iostream>

const char* InvalidGear::what() const noexcept
{
    return std::logic_error::what();
}

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear)
{
    // TODO: Add checking if gear is between -1 and gears_
    if(gear < -1 || gear > gears_) {
        throw InvalidGear{};
    }
    // -1 is for REAR
    // 0 is for NEUTRAL
    if(std::abs(currentGear_ - gear ) > 1) {
        throw InvalidGear{};
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
