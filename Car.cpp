#include "Car.hpp"
#include <iostream>
#include "ExceptionsCars.hpp"

Car::Car()
{
    std::cout << __FUNCTION__ << std::endl;
}
Car::~Car()
{
    std::cout << __FUNCTION__ << std::endl;
}

void Car::turnLeft()
{
    std::cout << __FUNCTION__ << std::endl;
}
void Car::turnRight()
{
    std::cout << __FUNCTION__ << std::endl;
}
void Car::brake()
{
    std::cout << __FUNCTION__ << std::endl;
}
void Car::accelerate(int speed)
{
    if (speed < 0) {
        throw InvalidAccelerate("Current accelerate " + std::to_string(accelerate_) + " and try to set " + std::to_string(speed) + " which is less than 0!");
    }
    accelerate_ = speed;
    std::cout << __FUNCTION__ << std::endl;
}