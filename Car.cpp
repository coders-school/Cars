#include "Car.hpp"

#include <iostream>

void Car::turnLeft()
{
    std::cout << "Car::" << __FUNCTION__ << std::endl;
}

void Car::turnRight()
{
    std::cout << "Car::" << __FUNCTION__ << std::endl;
}

void Car::brake()
{
    std::cout << "Car::" << __FUNCTION__ << std::endl;
}

void Car::accelerate(int)
{
    std::cout << "Car::" << __FUNCTION__ << std::endl;
}
