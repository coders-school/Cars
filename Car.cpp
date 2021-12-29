#include "Car.hpp"
#include <iostream>

void Car::turnLeft() {
    std::cout << __FUNCTION__ << std::endl;
}

void Car::turnRight() {
    std::cout << __FUNCTION__ << std::endl;
}

void Car::brake() {
    std::cout << __FUNCTION__ << std::endl;
}

void Car::setSpeed(const int speed) {
    std::cout << __FUNCTION__ << std::endl;
    if (speed < 0) {
        std::cout << "Negative speed not allowed. Setting speed to 0." << std::endl;
        speed_ = 0;
    } else if (speed > 200) {
        std::cout << "Speed over 200 not allowed. Setting speed to 200." << std::endl;
        speed_ = 200;
    } else {
        speed_ = speed;
    }
}
