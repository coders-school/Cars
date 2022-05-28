#include <iostream>
#include "PetrolEngine.hpp"

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{std::cout << __FUNCTION__ << std::endl;}

void PetrolEngine::setCurrentGear(int gear) {
    currentGear_ = gear;
}

bool PetrolEngine::isRunning() {
    return (currentGear_ != 0);
}

bool PetrolEngine::hasGear(int gear) {
    return (gear >= -1 && gear <= gears_);
}