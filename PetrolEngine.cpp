#include "PetrolEngine.hpp"
#include <iostream>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(1)
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear)
{
    if(gear < -1 || gear > gears_ || (currentGear_ != 0 && gear == -1)) {
        throw InvalidGear{};
    } else {
        currentGear_ = gear;
        std::cout << __FUNCTION__ << std::endl;
    }
}
