#include "PetrolEngine.hpp"

#include "CarExceptions.hpp"

#include <iostream>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << "PetrolEngine::" << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear) noexcept(false)
{
    throwOnUnallowedGearChange(gear);

    std::cout << "PetrolEngine::" << __FUNCTION__
              << " switching from " << currentGear_
              << " to " << gear << std::endl;

    currentGear_ = gear;
}

void PetrolEngine::throwOnUnallowedGearChange(int gear) const noexcept(false)
{
    if (gear < -1 || gear > gears_) {
        throw InvalidGear("Attempt to switch to gear out of possible range");
    }
    else if (gear == -1 && currentGear_ > 0) {
        throw InvalidGear("Attempt to switch to reverse from other than neutral");
    }
    else if (currentGear_ == -1 && gear > 0) {
        throw InvalidGear("Attempt to switch from reverse to other than neutral");
    }
}

int PetrolEngine::power() const
{
    return power_;
}

int PetrolEngine::capacity() const
{
    return capacity_;
}