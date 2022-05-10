#include <iostream>
#include "PetrolEngine.hpp"
#include "InvalidGear.hpp"

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power), capacity_(capacity), gears_(gears), currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear)
{
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    if (currentGear_ > 0 && gear == -1)
    {
        throw InvalidGear{"It is not possible to change gear from higher than 0 to R"};
    }
    if (gear > -1 && gear < gears_)
    {
        currentGear_ = gear;
    }

    std::cout << __FUNCTION__ << std::endl;
}