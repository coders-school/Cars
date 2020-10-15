#include "Car.hpp"
#include <iostream>
#include "InvalidSpeed.hpp"

Car::Car()
    : speed_(0) {
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
    speed_ = 0;
    std::cout << __FUNCTION__ << std::endl;
}
void Car::accelerate(int speed) {
    std::cout << __FUNCTION__ << std::endl;
    if (speed >= 0) {
        speed_ = speed;
    } else {
        throw InvalidSpeed("Negative value of velocity");
    }
}
int Car::getSpeed() const {
    return speed_;
}
