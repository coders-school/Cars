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
}
void Car::accelerate(int) {
    std::cout << __FUNCTION__ << std::endl;
}
int Car::getSpeed() const{
    return speed_;
}
