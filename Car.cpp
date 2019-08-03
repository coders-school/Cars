#include "Car.hpp"
#include <iostream>
#include "Exceptions.hpp"
#include <string>

void Car::turnLeft()         { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()  	     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake()           
{ 
    std::cout << __FUNCTION__ << std::endl; 
    velocity = 0;
} 
void Car::accelerateErr()            { std::cout << __FUNCTION__ << std::endl; }
void Car::accelerate(int speed)
{ 
    if (speed < 0)
        accelerateErr();
    else    
    {
        std::cout << __FUNCTION__ << std::endl; 
        velocity += speed;
    }
}
void Car::changeGear(Gear gear)
{
    if(currentGear == gear)
    {
        return;
    }
    
    try
    {
        if(currentGear > Gear::_N && gear == Gear::_R)
            throw InvalidGear();
        currentGear = gear;
        std::cout << "Current gear: " << gear::toString(currentGear) << std::endl;
    }
    catch (InvalidGear &error)
    {
        std::cout << error.what() << std::endl;
    }

}
