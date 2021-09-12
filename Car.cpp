#include "Car.hpp"
#include <iostream>

Car::~Car() {
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
    speed_ = speed;
}
int Car::getSpeed() const {
    return speed_;
}
