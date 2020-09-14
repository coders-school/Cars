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
    try {
        if (speed > currentSpeed_) {
            throw BreakeToHigherSpeedError(std::to_string(currentSpeed_));
        }
        setSpeed(speed);
    } catch (BreakeToHigherSpeedError& speed) {
        std::cerr << speed.what() << "\n";
    }
}
void Car::accelerate(int speed) {
    std::cout << __FUNCTION__ << ": ";
    try {
        if (speed < currentSpeed_ && speed > -20) {
            throw AccelerateToLoweSpeedError(std::to_string(currentSpeed_));
        }
        setSpeed(speed);
    } catch (AccelerateToLoweSpeedError& speed) {
        std::cerr << speed.what() << "\n";
    }
}
int Car::getSpeed() const {
    std::cout << "Car speed = " << currentSpeed_ << std::endl;
    return currentSpeed_;
}
void Car::setSpeed(int speed) {
    try {
        if (speed < -20) {
            throw ToLowSpeedError(std::to_string(speed));
        }
        if (speed > 200) {
            throw ToHighSpeedError(std::to_string(speed));
        }
        currentSpeed_ = speed;
        std::cout << "Car speed = " << currentSpeed_ << std::endl;
    } catch (ToLowSpeedError& speed) {
        std::cerr << speed.what() << "\n";
    } catch (ToHighSpeedError& speed) {
        std::cerr << speed.what() << "\n";
    }
}
