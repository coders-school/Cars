#include "Car.hpp"

#include <algorithm>
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
    speed_ = 0;
}

void Car::accelerate(int speed) {
    if(speed > 0){
    speed_ = std::min(speed_ + speed, maxSpeed_);
    }
}

int Car::getSpeed() const {
    return speed_;
}