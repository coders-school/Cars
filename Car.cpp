#include "Car.hpp"
#include <iostream>

unsigned Car::getVelocity()
{
    return velocity;
}

void Car::printVelocity()
{
    std::cout << "Current velocity is: " << velocity << std::endl;
}

unsigned Car::getMaxSpeed()
{
    return maxSpeed;
}

void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::accelerate(unsigned amount) 
{ 
    if(amount<=0) return;           
    if(velocity+amount>maxSpeed) 
    {
        velocity = maxSpeed;
        std::cout << "Hold your horses, Pal! ";
    }
    else
    {
        velocity += amount;  
        std::cout << "Your car has accelerated. ";
    }
    printVelocity();
}

void Car::brake(unsigned amount) 
{ 
    std::cout << __FUNCTION__ << std::endl;
    if(velocity>0 && amount>0)
    {
        if(amount>=velocity) velocity=0;
        else velocity-=amount;
        std::cout << "You have hit your brakes! ";
        printVelocity();
    }
    else return;
}


