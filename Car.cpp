#include "Car.hpp"
#include <iostream>
#include "ExceptionsClass.hpp"

void Car::accelerate(int speed) {
    if (speed < 0) {
        throw InvalidSpeed("Speed can't be less than zero");
    }

    speed_ = speed;
}

void Car::turnLeft() {
    std::cout << __FUNCTION__ << "\n";
}
void Car::turnRight() {
    std::cout << __FUNCTION__ << "\n";
}
void Car::brake() {
    speed_ = 0;
    std::cout << __FUNCTION__ << "\n";
}
