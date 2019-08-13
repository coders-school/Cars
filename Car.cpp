#include "Car.hpp"
#include <iostream>

Car::Car()
{
    maxSpeed_ = 220;
}

Car::Car(int maxSpeed)
    : maxSpeed_ (maxSpeed)
{

}

void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake()         
{ 
    velocity_ = 0;
    std::cout << __FUNCTION__ << std::endl; 
}
void Car::accelerate(int speed) 
{ 
    if(speed >= 0 && speed <= maxSpeed_)
    {
        velocity_ = speed;
        std::cout << __FUNCTION__ << " Speed: " << speed << std::endl; 
    }
    else
    {
        throw MyException();
    }   
}
int Car::getVelocity() const
{
    return velocity_;
}

