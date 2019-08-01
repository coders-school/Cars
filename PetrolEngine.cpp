#include "PetrolEngine.hpp"
#include <iostream>
#include <stdexcept>

PetrolEngine::PetrolEngine(unsigned power, float capacity, int gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}

unsigned PetrolEngine::getEnginePower() const
{
    return power_;
}

int PetrolEngine::getCurrentGear() const
{
    return currentGear_;
}

bool PetrolEngine::isGearInRange(int gear)
{
    return gear <= gears_ && gear >= -1;
}

bool PetrolEngine::doesGearChangeImmediatelyFromForwardToReverse(int gear)
{
    return currentGear_ > 0 && gear == -1; 
}

bool PetrolEngine::doesGearChangeImmediatelyFromReverseToForward(int gear)
{
    return currentGear_ == -1 && gear > 0; 
}

void PetrolEngine::checkIfChangingIsAllowed(int gear)
{
    if(not isGearInRange(gear)) 
    {
        throw std::out_of_range("Chosen gear is out of range!");
    }

    if(doesGearChangeImmediatelyFromForwardToReverse(gear) or doesGearChangeImmediatelyFromReverseToForward(gear))
    {
        throw std::logic_error("Forbidden gear change!");
    }
}

void PetrolEngine::changeGear(int gear)
{
    checkIfChangingIsAllowed(gear);   
    currentGear_ = gear;
    std::cout << "You've changed gear to " << currentGear_ << std::endl;
}
