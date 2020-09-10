#include "Car.hpp"
#include <iostream>

void Car::turnLeft() {
}
void Car::turnRight() {
}
void Car::brake() {
    currentSpeed_ = 0;
}
void Car::accelerate(int speed) {
    currentSpeed_ += speed > 0 ? speed : 0;
}

int Car::checkSpeed() {
    return currentSpeed_;
}