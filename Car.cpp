#include "Car.hpp"
#include <iostream>

void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake()         { std::cout << __FUNCTION__ << std::endl; }
void Car::accelerate(unsigned amount) 
{ 
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
    std::cout << "Current velocity is: " << velocity << std::endl;
}
