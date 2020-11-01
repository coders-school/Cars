#include "Car.hpp"
#include <iostream>
#include "Exceptions.hpp"

void Car::turnLeft() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::turnRight() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::accelerate(int speed) {
    if (speed < 0) {
        throw InvalidSpeed("Speed can't be less than zero.");
    } else {
        speed_ += speed;
    }
}
void Car::decelerate(int speed) {
    if (speed < 0) {
        throw InvalidSpeed("Speed can't be less than zero.");
    } else if (speed_ - speed < 0) {
        throw InvalidSpeed("You can't decelerate that much.");
    } else {
        speed_ -= speed;
    }
}
void Car::brake() {
    speed_ = 0;
}
