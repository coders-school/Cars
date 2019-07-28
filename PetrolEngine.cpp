#include "PetrolEngine.hpp"
#include <iostream>
#include <stdexcept>

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
    if(gear <= gears_ && gear >= -1) 
    {
        try
        {
            if( (currentGear_ > 0 && gear == -1) || (currentGear_ == -1 && gear > 0) )
            {
                throw std::logic_error("Forbidden gear change!");
            }
            else
            {
                currentGear_ = gear;
                std::cout << "You've changed gear to " << currentGear_ << std::endl;
            }
        }
        catch(std::logic_error &ex1)
        {
            std::cout << ex1.what() << std::endl;
        }
    }
    else
    {
        try
        {
            throw std::out_of_range("Chosen gear is out of range!");
        }
        catch(std::out_of_range &ex2)
        {
            std::cout << ex2.what() << std::endl;
        }
    }
}
