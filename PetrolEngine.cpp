#include "PetrolEngine.hpp"
#include <iostream>

PetrolEngine::PetrolEngine(unsigned power, float capacity, int gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}

unsigned PetrolEngine::getEnginePower() const
{
    return power_;
}

int PetrolEngine::getCurrentGear() const
{
    return currentGear_;
}

void PetrolEngine::changeGear(int gear)
{
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL

    if(gear <= gears_ && gear >= -1) 
    {
        if( (currentGear_ > 0 && gear == -1) || (currentGear_ == -1 && gear > 0) )
        {
            std::cout << "Invalid gear!\n";
        }
        else
        {
            currentGear_ = gear;
            std::cout << "You've changed gear to " << currentGear_ << std::endl;
        }
    }
    else std::cout << "Not a valid gear!\n";
}
