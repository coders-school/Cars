#include "Car.hpp"

#include <iostream>

void Car::turnLeft() { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight() { std::cout << __FUNCTION__ << std::endl; }
void Car::brake() { std::cout << __FUNCTION__ << std::endl; }

void Car::accelerate(int speed)
{
    std::cout << __FUNCTION__ << std::endl;
    if (speed > 0 && speed < 50) {
        speed_ += speed;
    }
}

int Car::getSpeed() const
{
    std::cout << __FUNCTION__ << std::endl;
    return speed_;
}
