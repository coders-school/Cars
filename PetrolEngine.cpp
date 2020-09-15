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
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    if(gear >= -1 && gear < gears_){
        currentGear_ = gear;
    } else throw WrongGearException(gear, this->gears_);

    std::cout << __FUNCTION__ << " to: " << this->currentGear_ << std::endl;
}
