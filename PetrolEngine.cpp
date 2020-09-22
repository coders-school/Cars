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
    if(gear < REAR_GEAR || gear > gears_){
        throw GearException("This car don't have " + std::to_string(gear) + " gear.\n");
    }
    if(abs(gear - currentGear_) > 2) {
        throw GearException("Can't change gear by more than two.\n");
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
