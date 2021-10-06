#include "Car.hpp"
#include <iostream>
#include "Exceptions.hpp"

Car::Car() {
    std::cout << __FUNCTION__ << std::endl;
}

Car::~Car()       { std::cout << __FUNCTION__ << std::endl; }
void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }

void Car::brake() {
    std::cout << __FUNCTION__ << std::endl;
    currentSpeed_ = 0;
}

void Car::accelerate(int speed) {
    std::cout << __FUNCTION__ << std::endl;
    if (speed >= 0 && speed < MAX_SPEED_) {
        currentSpeed_ = speed;
    } else {
        throw InvalidSpeed("Speed is out of possible range.");
    }
}

bool Car::isStopped() {
    return currentSpeed_ == 0;
}

int Car::getSpeed() {
    return currentSpeed_;
}
