#include "PetrolEngine.hpp"
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
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL

    if(gear < 0 || gear > gears_ && gear != 'R'){
        throw InvalidGear("Wrong gear!");
    }
    if((currentGear_ - 1) == gear || (currentGear_ + 1) == gear ||
        (currentGear_ == 0 && gear == 'R') || (currentGear_ == 'R' && gear == 0)){
        currentGear_ = gear;
        std::cout << __FUNCTION__ << std::endl;
    }else{
        throw InvalidGear("Wrong gear!");
    }

}
