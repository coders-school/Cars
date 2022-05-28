#include <iostream>
#include "PetrolEngine.hpp"

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
    if(gear > gears_ || gear < -1) {throw InvalidGear{"Engine does not have this gear!"};}
    if(gear == -1 && currentGear_ > 0) {
        throw InvalidGear{"Cannot change to REAR from other gears than NEUTRAL!"};
    } else {currentGear_ = gear;}
    std::cout << __FUNCTION__ << std::endl;
}

bool PetrolEngine::isRunning() {
    return (currentGear_ != 0);
}
