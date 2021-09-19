#include "Car.hpp"
#include "../exception/InvalidSpeed.hpp"
#include <iostream>

void Car::turnLeft() {
    std::cout << __FUNCTION__ << std::endl;
}

void Car::turnRight() {
    std::cout << __FUNCTION__ << std::endl;
}

void Car::brake() {
    speed_ = 0;
    std::cout << __FUNCTION__ << std::endl;
}

void Car::accelerate(int speed) { 
    if (speed < 0) {
        throw InvalidSpeed("> negative speed!");
    }
    speed_ += speed;    
    std::cout << __FUNCTION__ << std::endl;
}

int Car::getSpeed() {
    return speed_;
}
