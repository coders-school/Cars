#include "Car.hpp"
#include <iostream>
#include "Exceptions.hpp"
#include <string>

void Car::turnLeft()         { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()  	     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake()           
{
    velocity = 0;
}

void Car::accelerate(int acceleration)
{ 
    if(acceleration == 0)
    {
        return;
    }

    if(acceleration < 0)
    {        
        throw InvalidAccelerationValue(
            std::to_string(acceleration));
    }
    else    
    {
        velocity += acceleration;
    }
}

void Car::changeGear(Gear gear)
{
    if(currentGear == gear)
    {
        return;
    }
    
    if(currentGear > Gear::_N 
        && gear == Gear::_R)
    {
        throw InvalidGear();
    }
    currentGear = gear;
}

Gear Car::getGear() const
{
    return currentGear;
}

int Car::getVelocity() const
{
    return velocity;
}
