#include <iostream>

#include "Car.hpp"

constexpr int topSpeed = 200;
constexpr int lowestSpeed = -15;
constexpr int highestSpeed = 100;

Car::~Car() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::turnLeft() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::turnRight() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::brake(int power) {
    if(speed_ > power){
        speed_ -= power;
    }
    else{
        speed_ = 0;
    }
    
}
void Car::accelerate(int speed) {
    std::cout << __FUNCTION__ << std::endl;

    auto isValidAccelerate = [](const auto& speed) { return speed >= lowestSpeed && 
                                                            speed <= highestSpeed; };

    if (!isValidAccelerate(speed)) {
        throw InvalidAccelerationException("Acceleration value is invalid");
    }

    speed_ += speed;
}

int Car::getSpeed() {
    std::cout << __FUNCTION__ << std::endl;
    return speed_;
}
