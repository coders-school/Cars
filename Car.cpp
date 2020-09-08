#include <iostream>
#include "Car.hpp"

Car::Car() {}

Car::~Car()             { std::cout << __FUNCTION__ << std::endl; }
void Car::turnLeft()    { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()   { std::cout << __FUNCTION__ << std::endl; }
void Car::brake()       { std::cout << __FUNCTION__ << std::endl; }
void Car::accelerate(int speed){
    if (speed >= 0) {
        speed_ = speed;
    }
    std::cout << __FUNCTION__ << speed << std::endl;
}

int Car::getSpeed() {
    return speed_;
}
