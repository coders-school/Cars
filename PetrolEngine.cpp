#include "PetrolEngine.hpp"
#include "InvalidGear.hpp"
#include <iostream>

PetrolEngine::PetrolEngine(Power power, PetrolCapacity capacity, ManualGear gears)
    : Engine(power)
    , capacity_(capacity)
    , gears_(gears)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolEngine::~PetrolEngine() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(ManualGear gear){
    if(currentGear_ < ManualGear::neutral && gear > ManualGear::neutral){
        throw InvalidGear("InvalidGear error: change from R to gear");
    }
    if(currentGear_ > ManualGear::neutral && gear < ManualGear::neutral){
        throw InvalidGear("InvalidGear error: change from gear to R");
    }
    if(gear > gears_) {
        throw InvalidGear("InvalidGear error: gear to high to change");
    }

    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}