#include <iostream>

#include "exceptions.hpp"
#include "PetrolEngine.hpp"



PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : Engine(power)
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

    if(currentGear_ == gear)
    {
        return;
    }

    if(gear < -1 || gear > gears_)
    {
        //throw InvalidGear("There is no such gear.");
        throw InvalidGear();
    }

    if( (currentGear_ > 1 && gear == -1) ||
        (currentGear_ == 0 && gear == gears_ && gears_ > 2) )
    {
        throw InvalidGear("Invalid gear change.");
    }

    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}

PetrolEngine::~PetrolEngine()
{
    std::cout << __FUNCTION__ << std::endl;
}

std::ostream & operator<<(std::ostream & out, PetrolEngine const & engine)
{
    out << "Petrol engine: power: "<< engine.getPower() 
        << "\tCapacity: " << engine.getCapacity() 
        << "\tGears: " << engine.getGears()
        << "\tCurrent gear: " << engine.getCurrentGear();

    return out;
}   