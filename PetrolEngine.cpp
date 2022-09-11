#include "PetrolEngine.hpp"

#include <iostream>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << "PetrolEngine::" << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear)
{
    if (gear >= -1 && gear <= gears_) {
        currentGear_ = gear;
    }
    std::cout << "PetrolEngine::" << __FUNCTION__ << std::endl;
}
