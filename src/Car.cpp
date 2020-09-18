#include <iostream>

#include "Car.hpp"

constexpr int topSpeed = 200;

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
}
void Car::accelerate(int speed) {
    std::cout << __FUNCTION__ << std::endl;

    auto isValidAccelerate = [](const auto& speed) { return speed >= -15 && speed <= 100; };

    if (!isValidAccelerate(speed)) {
        throw InvalidAccelerationException("Acceleration value is invalid");
    }

    speed_ += speed;
}

int Car::getSpeed() {
    std::cout << __FUNCTION__ << std::endl;
    return speed_;
}
