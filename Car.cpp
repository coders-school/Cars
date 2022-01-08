#include "Car.hpp"
#include <iostream>

void Car::turnLeft(){ 
    direction_ = "left";
    std::cout << __FUNCTION__ << std::endl;
}

void Car::turnRight(){ 
    direction_ = "right"; 
    std::cout << __FUNCTION__ << std::endl;
}

void Car::brake(){ 
    speed_ = 0;
    direction_ = "straight";
    std::cout << __FUNCTION__ << std::endl;
}

void Car::accelerate(int speed){
    if (speed >= 0 && speed < maxSpeed_){
        speed_ += speed;
    } else {
        throw InvalidSpeed("Speed out of range!");
    }
    std::cout << __FUNCTION__ << std::endl;
}
