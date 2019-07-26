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
    if(-1 <= gear && gear <= PetrolEngine::gears_)
    {
        currentGear_ = gear;
        std::cout << __FUNCTION__ <<" to: "<<currentGear_<< std::endl;
    }
    else if(gear < -1 || gears_ < gear)
        throw std::out_of_range ("Invalid gear!");
    else if(gear == -1 && currentGear_ > 1)
        throw std::out_of_range ("Invalid gear! You can change to R only from 1 or N");
}
