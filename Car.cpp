#include "Car.hpp"

#include <iostream>

Car::Car() {
    std::cout << __FUNCTION__ << std::endl;
}

Car::~Car() {
    std::cout << __FUNCTION__ << std::endl;
}

void Car::turnLeft() {
    std::cout << __FUNCTION__ << std::endl;
}

void Car::turnRight() {
    std::cout << __FUNCTION__ << std::endl;
}

void Car::brake() {
    std::cout << __FUNCTION__ << std::endl;
    setSpeed(MINIMUM_VELOCITY);
}

void Car::accelerate(int speed) {
    if (speed < MINIMUM_VELOCITY) {
        std::cout << "Negative value of velocity is not allowed!\n";
        return;
    }

    setSpeed(speed);
    std::cout << __FUNCTION__ << std::endl;
}
