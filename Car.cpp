#include "Car.hpp"

void Car::turnLeft() { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight() { std::cout << __FUNCTION__ << std::endl; }
void Car::brake() 
{
    if(currentSpeed_ == 0)
    {
        throw std::invalid_argument("Current speed is already 0");
    }
    currentSpeed_ = 0;
}
void Car::accelerate(int speed) 
{ 
    if(speed < 0)
    {
        throw std::invalid_argument("Speed cannot be below 0");
    }
    if(speed > 200)
    {
        throw std::invalid_argument("Speed cannot be higher than 200");
    }
}
