#include "PetrolEngine.hpp"
#include "Exceptions.hpp"

#include <iostream>
#include <sstream>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    if(power_ < 1) {
        throw std::invalid_argument("Power can't be lower than 1");
    }
    if(capacity_ < 1) {

        throw std::invalid_argument("Capacity can't be lower than 1");
    }
    if(gears_ < 1) {
        throw std::invalid_argument("gears need to be grater than 1");
    }

    std::cout << __FUNCTION__ << std::endl;
}

int PetrolEngine::getPower() const
{ 
    std::cout << __FUNCTION__ << " Your power is: " << power_ << std::endl;
    return power_; 
    
}

int PetrolEngine::getCapacity() const
{ 
    std::cout << __FUNCTION__ << " Your capacity is: " << capacity_ << std::endl;
    return capacity_;
    
}

int PetrolEngine::getMaxGear() const 
{
    std::cout << __FUNCTION__ << " Your top Gear is: " << gears_ << std::endl;
    return gears_;
    
}

int PetrolEngine::getCurrentGear() const
{
    std::cout << __FUNCTION__ << " Your gear is: " << currentGear_ << std::endl;
    return currentGear_;
    
}


void PetrolEngine::changeGear(int gear)
{
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL

    std::ostringstream oos;
     if(gear > gears_ || gear < -1 ) {
        oos << "This Care have gear -1, 0 ... to " << gears_;
        throw InvalidGear(oos.str());
    }
    
    currentGear_ = gear;
    oos << " Your current gear is: " << currentGear_;
    
    std::cout << __FUNCTION__ << ": " << oos.str() << std::endl;
}
