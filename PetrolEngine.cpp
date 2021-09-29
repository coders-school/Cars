#include "PetrolEngine.hpp"

#include <cmath>
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
    if (gear < -1) {
        throw InvalidGear("gear to low");
    } 
    if (gear > gears_) {
        throw InvalidGear("gear to high");  
    } 
    if (std::abs(currentGear_ - gear) != 1) {
        throw InvalidGear("too fast gear shift");
    } 
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
