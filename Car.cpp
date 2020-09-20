#include "Car.hpp"
#include "iostream"

Car::~Car() {}
void Car::turnLeft() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::turnRight() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::brake() {
    speed_ = 0;
}
void Car::accelerate(int speed) {
    if (speed < 0) {
        throw InvalidSpeed("Can not drive with speed less than 0");
    } else {
        speed_ = speed;
    }
}

void Car::showSpeed() {
    std::cout << "Speed = " << speed_ << '\n';
}

int Car::getSpeed() {
    return speed_;
}