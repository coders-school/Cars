#include "PetrolEngine.hpp"
#include <iostream>
#include <string>


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
    if(gear < -1 || gear > gears_) {
        throw InvalidGear("Invalid gear. Gear needs to be between 1 and " + std::to_string(gear));   
    }
    if(gear != 0 && abs(gear - currentGear_) != 1) {
        throw InvalidGear("Invalid gear change from: " + std::to_string(currentGear_)+ " to: " + std::to_string(gear));
    }
    currentGear_ = gear;

    std::cout << __FUNCTION__ << std::endl;
}
