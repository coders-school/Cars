#include "Car.hpp"
#include <iostream>

bool Car::Speed::operator!=(const Speed& other) const {
    return this->val != other.val;
}

bool Car::Speed::operator>(const Speed& other) const {
    return this->val > other.val;
}

bool Car::Speed::operator<(const Speed& other) const {
    return this->val < other.val;
}

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
    speed_ = Speed(0);
}
void Car::accelerate(const Speed& speed) {
    std::cout << __FUNCTION__ << std::endl;
    if(speed < Speed(0)) {
        std::cout << "Negative speed not provided\n";
        return;
    }
    if(speed > Speed(200)) {
        std::cout << "Speed limiter installed, sorry.\n";
        return;
    }
    speed_ = speed;
}
Car::Speed Car::getSpeed() const {
    return speed_;
}
