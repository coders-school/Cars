#include "Car.hpp"
#include <iostream>

void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
int Car::getVelocity()   { return velocity; }
void Car::brake()         
{   
    velocity=0; 
    std::cout << __FUNCTION__ << std::endl; }
void Car::accelerate(int speed) 
{ 
    if(speed<0)
    {
        if(velocity<abs(speed))
        {
            std::cout << "There is impossible to drive slower than 0 km/h." << std::endl;
            velocity+=speed;
        }
        if(velocity>abs(speed))
        {
            velocity+=speed;
            std::cout << "Now your velocity is ";
            std::cout << velocity;
            std::cout << " km/h." << std::endl;
        }
    }
    if(speed>0)
    {
        int tempSpeed=velocity+speed;
        if(tempSpeed>220)
        {
            std::cout << "Max speed for this car is 220. You can't drive faster."<<std::endl;
            velocity+=speed;
        }
        else
        {
            velocity+=speed;
            std::cout << "Now your velocity is ";
            std::cout << velocity;
            std::cout << " km/h." << std::endl;

        }
    }
    std::cout << __FUNCTION__ << std::endl; }
