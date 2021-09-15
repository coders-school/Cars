#include "PetrolEngine.hpp"
#include <iostream>
#include <numeric>

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
  
    if ( ((gear < -1) || (gear > 5)) || ((currentGear_!=0) && (gear=-1)) ) {throw InvalidGear("invalid gear error");};

    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
