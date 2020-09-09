#include "InvalidGear.hpp"
#include "PetrolEngine.hpp"
#include <iostream>

constexpr int GEAR_REAR = -1;
constexpr int GEAR_NEUTRAL= 0;

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
    if (gear < GEAR_REAR || gear > gears_) {
        throw InvalidGear("Gear out of range");
    }
    if (currentGear_ > GEAR_NEUTRAL && gear == GEAR_REAR) {
        throw InvalidGear("You can change to REAR only from NEUTRAL");
    }
    if (currentGear_ == GEAR_REAR && gear > GEAR_NEUTRAL) {
        throw InvalidGear("You cannot change to forward gears from REAR");
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
