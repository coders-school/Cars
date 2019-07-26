#include "PetrolEngine.hpp"
#include <iostream>
#include <stdexcept>

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
    // -1 is for REAR
    // 0 is for NEUTRAL
   
    try
    {
        if (gear >= -1 && gear < gears_)
        {
            currentGear_ = gear;
            std::cout << __FUNCTION__ << std::endl;
        }
        else throw std::out_of_range ("Invalid Gear");
    }

    catch (std::out_of_range  &text) { std::cout<<text.what()<<std::endl;}
}
int PetrolEngine::getCurrentGear()
{
    return currentGear_;
}


