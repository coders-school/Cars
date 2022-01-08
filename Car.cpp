#include "Car.hpp"
#include <iostream>

void Car::turnLeft(){ 
    direction_ = "left";
}

void Car::turnRight(){ 
    direction_ = "right"; 
}

void Car::brake(){ 
    speed_ = 0;
    direction_ = "straight";
}

void Car::accelerate(int speed){
    if (speed >= 0 && speed < maxSpeed_){
        speed_ += speed;
    } else {
        throw InvalidSpeed("Speed out of range!");
    }
    
}
