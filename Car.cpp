#include "Car.hpp"

#include <iostream>

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
    if (speed >= 0 && speed < 300) {
        speed_ = speed;
    } else {
        std::cout << "Your car cannot accelerate to this speed, sorry.\n";
    }
}

int Car::getSpeed() {
    return speed_;
}
