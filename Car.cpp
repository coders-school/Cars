#include "Car.hpp"
#include <iostream>
#include <stdexcept>
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

void Car::changeGear(int gear)
{
    try
    {
        if( currentGear > 0 && gear == -1 )
            throw std::runtime_error("You can not change the current gear to R. Slow down!");
        currentGear = gear;
        std::cout << "Current gear: " << currentGear << std::endl;
    }
    catch (std::runtime_error &error)
    {
        std::cout << "Invalid Gear!" << std::endl;
        std::cout << error.what() << std::endl;
    }

}
