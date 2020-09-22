#include <iostream>

#include "SpeedException.hpp"
#include "Car.hpp"

Car::~Car()               { std::cout << __FUNCTION__ << std::endl; }
void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }

void Car::brake() {
    currentSpeed_ = 0;
    std::cout << __FUNCTION__ << std::endl;
}

void Car::accelerate(int speed) {
    if(speed > maxSpeed_){
        throw SpeedException("Too fast\n");
    }
    if(speed < 0){
        throw SpeedException("Speed can't be a negative number\n");
    }
    currentSpeed_ = speed;
    std::cout << __FUNCTION__ << std::endl;
}