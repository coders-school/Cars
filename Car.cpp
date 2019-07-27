#include "Car.hpp"
#include <iostream>

void Car::turnLeft()                 { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()                { std::cout << __FUNCTION__ << std::endl; }
void Car::brake()                    { std::cout << __FUNCTION__ << std::endl; }
void Car::accelerateErr()            { std::cout << __FUNCTION__ << std::endl; }
void Car::accelerate(int speed)
{ 
    if (speed <= 0)
        accelerateErr();
    else    
         std::cout << __FUNCTION__ << std::endl; 
}

