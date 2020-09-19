#include "Car.hpp"

#include <iostream>

#include "Exceptions.hpp"

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
    speed_ = 0;
}

void Car::accelerate(int speed) {
    std::cout << __FUNCTION__ << std::endl;
    if (speed >= minSpeed && speed < maxSpeed) {
        speed_ = speed;
    } else {
        throw InvalidAcceleration("Your car cannot accelerate to this speed, sorry.\n");
    }
}

void Car::decelerate(int speed) {
    std::cout << __FUNCTION__ << std::endl;
    if (speed >= minSpeed && speed <= speed_) {
        speed_ -= speed;
    } else {
        throw InvalidAcceleration("Your car cannot decelerate this speed, sorry.\n");
    }
}

int Car::getSpeed() {
    return speed_;
}
