#include "Car.hpp"
#include <iostream>

Car::Car() {
    std::cout << __FUNCTION__ << " - ";
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

void Car::brake(int speed) {
    std::cout << __FUNCTION__ << ": ";
    if (speed > currentSpeed_) {
        throw BrakeToHigherSpeedError(std::to_string(currentSpeed_));
    }
    setSpeed(speed);
}

void Car::accelerate(int speed) {
    std::cout << __FUNCTION__ << ": ";
    if (speed < currentSpeed_ && speed > maxReverseSpeed) {
        throw AccelerateToLoweSpeedError(std::to_string(currentSpeed_));
    }
    setSpeed(speed);
}

void Car::setSpeed(int speed) {
    if (speed < maxReverseSpeed) {
        throw ToLowSpeedError(std::to_string(speed));
    }
    if (speed > maxSpeed) {
        throw ToHighSpeedError(std::to_string(speed));
    }
    currentSpeed_ = speed;
    std::cout << "Car speed = " << currentSpeed_ << std::endl;
}

int Car::getSpeed() const {
    std::cout << "Car speed = " << currentSpeed_ << std::endl;
    return currentSpeed_;
}
