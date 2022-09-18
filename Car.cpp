#include "Car.hpp"

#include <iostream>

Car::Car(int maxSpeed, int maxReverseSpeed)
    : maxSpeed_(maxSpeed)
    , maxReverseSpeed_(maxReverseSpeed)
{
    if (maxSpeed <= 0) {
        throw std::invalid_argument { "Non-positive value for maxSpeed passed on construction" };
    }
    if (maxReverseSpeed >= 0) {
        throw std::invalid_argument { "Non-negative value for maxReverseSpeed passed on construction" };
    }
}

void Car::turnLeft()
{
    std::cout << "Car::" << __FUNCTION__ << std::endl;
}

void Car::turnRight()
{
    std::cout << "Car::" << __FUNCTION__ << std::endl;
}

int Car::currentSpeed() const
{
    return currentSpeed_;
}

void Car::brake(int desiredSpeed)
{
    if (currentSpeed_ > 0 && desiredSpeed >= 0 && desiredSpeed < currentSpeed_) {
        currentSpeed_ = desiredSpeed;
    }
    else if (currentSpeed_ < 0 && desiredSpeed <= 0 && desiredSpeed > currentSpeed_) {
        currentSpeed_ = desiredSpeed;
    }

    std::cout << "Car::" << __FUNCTION__
              << " Requested final speed: " << desiredSpeed
              << " Final speed: " << currentSpeed_ << std::endl;
}

void Car::accelerate(int speedChange)
{
    if (currentSpeed_ > 0) {
        changeForwardSpeed(speedChange);
    }
    else if (currentSpeed_ < 0) {
        changeReverseSpeed(speedChange);
    }
    else {
        startMoving(speedChange);
    }

    std::cout << "Car::" << __FUNCTION__
              << " Requested speed change: " << speedChange
              << " Final speed: " << currentSpeed_ << std::endl;
}

void Car::startMoving(int speedChange)
{
    if (speedChange >= 0) {
        currentSpeed_ = speedChange >= maxSpeed_ ? maxSpeed_
                                                 : speedChange;
        return;
    }

    currentSpeed_ = speedChange <= maxReverseSpeed_ ? maxReverseSpeed_
                                                    : speedChange;
}

void Car::changeForwardSpeed(int speedChange)
{
    if (speedChange > 0) {
        int new_speed = currentSpeed_ + speedChange;
        currentSpeed_ = new_speed >= maxSpeed_ ? maxSpeed_
                                               : new_speed;
    }
}

void Car::changeReverseSpeed(int speedChange)
{
    if (speedChange < 0) {
        int new_speed = currentSpeed_ + speedChange;
        currentSpeed_ = new_speed <= maxReverseSpeed_ ? maxReverseSpeed_
                                                      : new_speed;
    }
}
