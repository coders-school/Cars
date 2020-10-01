#include "PetrolEngine.hpp"
#include "CarExceptions.hpp"
#include <iostream>
#include <stdlib.h> 

PetrolEngine::PetrolEngine(Power power, Capacity capacity, Gears gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; 
}

void PetrolEngine::changeGear(int gear)
{
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL

    std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; 
    if(abs(gear - currentGear_) != 1 or gear < -1  or gear > gears_.gears_) 
    {
        throw InvalidGear("Zgrzyyyyt!");
    }
    currentGear_ = gear;
}

PetrolEngine::~PetrolEngine() { std::cout << __FUNCTION__ << std::endl; }

void PetrolEngine::start() const {std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; 
};
void PetrolEngine::stop() const {std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; 
};


