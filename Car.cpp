#include "Car.hpp"

#include <iostream>

void Car::turnLeft() { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight() { std::cout << __FUNCTION__ << std::endl; }
void Car::brake() { std::cout << __FUNCTION__ << std::endl; }

void Car::accelerate(int speed) {
    std::cout << __FUNCTION__ << std::endl;

    auto validSpeed = [](const int speed) { return speed >= 0 and speed <= 100; };

    if (validSpeed(speed)) {
        speed_ += speed;
    }
}
