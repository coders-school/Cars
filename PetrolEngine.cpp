#include <iostream>
#include "PetrolEngine.hpp"


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
    if(gear >= -1 && gear <= gears_)
    {
        currentGear_ = gear;
    }
    else
    {
        throw MyException();
    }
       
    std::cout << __FUNCTION__ << " Current gear: " << currentGear_ << std::endl;
}

int PetrolEngine::getCurrentGear() const
{
    return currentGear_;
}
