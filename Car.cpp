#include "Car.hpp"
#include <iostream>

void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake()         { std::cout << __FUNCTION__ << std::endl; }
void Car::accelerate(int amount) 
{ 
    if(amount > 0) 
    {
        velocity += amount;
        std::cout << "Your car has accelerated. Current velocity is: " << velocity << std::endl;
    }
    
}
