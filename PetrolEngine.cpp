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
    if(gear>0 && currentGear_ == -1){
        throw InvalidGear ("You can't go forward when you have REAR on!");
    }
    if(gear == -1 && currentGear_ != 0){
        throw InvalidGear ("You can't turn on REAR while driving!");
    }
    if(gear < -1 || gear > 5){
        throw InvalidGear ("There is no such option!");
    }

    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}

