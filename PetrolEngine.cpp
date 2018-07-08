#include "PetrolEngine.hpp"
#include <iostream>

PetrolEngine::PetrolEngine(int power,
                           float capacity,
                           int gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear)
{
    std::cout << __FUNCTION__ << std::endl;
    if (gear > 6)
    {
        throw InvalidGear();
    }
    currentGear_ = gear;
}
