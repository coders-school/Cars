#include "PetrolEngine.hpp"
#include <iostream>

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
    if ((gear < -1) or (gear > gears_)) {
        throw InvalidGear{};
    } else if ((currentGear_ > 0) and (gear == -1)) {
        throw InvalidGear{};
    } else if ((currentGear_ == -1) and (gear > 0)) {
        throw InvalidGear{};
    }

    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
