#include "PetrolEngine.hpp"
#include <iostream>
#include <exception>

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
    
    std::cout << __FUNCTION__ << std::endl;
        if (gear >= -1 && gear <= gears_) 
        {
                if (currentGear_ == -1 && gear > 1)
                {   
                    throw std::logic_error("Can't change gear from rear to higher than 1");
                }

                if (currentGear_ > 1 && gear == -1) 
                {
                    throw std::logic_error("Can't change gear from higher than one to rear");
                }
                
                else {currentGear_ = gear;}
        }
        else {throw std::out_of_range("Invalid gear!");}

}

int PetrolEngine::returnGear()
{
    return currentGear_;
}
