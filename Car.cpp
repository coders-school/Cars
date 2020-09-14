#include "Car.hpp"

#include <iostream>

#include "InvalidSpeed.hpp"

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
        throw InvalidSpeed("Negative value of velocity is not allowed!");
    }

    setSpeed(speed);
    std::cout << __FUNCTION__ << std::endl;
}
