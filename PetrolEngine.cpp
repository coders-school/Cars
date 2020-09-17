#include <iostream>

#include "PetrolEngine.hpp"
#include "GearException.hpp"

constexpr short NEUTRAL_GEAR = 0;
constexpr short REAR_GEAR = -1;

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
    if(currentGear_ < REAR_GEAR || currentGear_ > gears_){
        throw GearException("This car don't have " + std::to_string(gear) + " gear.\n");
    }
    if(gear == REAR_GEAR && currentGear_ != NEUTRAL_GEAR){
        throw GearException("Can't change gear while current is not neutral.\n");
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
