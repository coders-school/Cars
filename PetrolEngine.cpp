#include "PetrolEngine.hpp"
#include "InvalidGear.hpp"
#include <iostream>

PetrolEngine::PetrolEngine(int power, float capacity, int gears=6)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolEngine::~PetrolEngine()
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear)
{
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    if (isGearValid(gear))
    {
    	currentGear_ = gear;
    	std::cout << __FUNCTION__ << std::endl;
    }
    else
    {
	std::cout<<"This gear is not valid." <<std::endl;
    }
}

int PetrolEngine::getGear()
{
    return currentGear_;
}

bool PetrolEngine::isGearValid(int& gear)
{
    return (gear <= gears_ && gear >= -1) ? true : false;
}
