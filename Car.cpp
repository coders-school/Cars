#include "Car.hpp"
#include <iostream>

int Car::getVelocity()
{
    return velocity;
}

void Car::printVelocity()
{
    std::cout << "Current velocity is: " << velocity << std::endl;
}

void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::accelerate(int amount) 
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

void Car::brake(int amount) 
{ 
    std::cout << __FUNCTION__ << std::endl;
    if(amount<=0) return;
    if(velocity==0 && amount>0) std::cout << "You don't have to hold brakes when you're not moving! \n";
    if(velocity>0 && amount>0)
    {
        if(amount>=velocity) velocity=0;
        else velocity-=amount;
        std::cout << "You have hit your brakes! ";
    }
    printVelocity();
}


