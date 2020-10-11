#include "Car.hpp"

#include <iostream>

#include "Exception.hpp"

void Car::turnLeft() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::turnRight() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::brake() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::accelerate(int speed) {
    if (speed < 0) {
        throw InvalidAcceleration("You cannot change speed to negative value.");
    }
    speed_ = speed;
    std::cout << __FUNCTION__ << std::endl;
}
