#include "Car.hpp"
#include <iostream>

class ToLowSpeedError : public std::logic_error {
public:
    ToLowSpeedError(std::string speed)
        : std::logic_error("To Low Speed Error - speed " + speed + " cannot be set for this car.") {}
};

class ToHighSpeedError : public std::logic_error {
public:
    ToHighSpeedError(std::string speed)
        : std::logic_error("To High Speed Error - speed " + speed + " cannot be set for this car.") {}
};

class AccelerateToLoweSpeedError : public std::logic_error {
public:
    AccelerateToLoweSpeedError(std::string speed)
        : std::logic_error("You cannot accelerato to lower speed than actual (" + speed + ").") {}
};

class BreakeToHigherSpeedError : public std::logic_error {
public:
    BreakeToHigherSpeedError(std::string speed)
        : std::logic_error("You cannot breake to higher speed than actual (" + speed + ").") {}
};

Car::Car() {
    std::cout << __FUNCTION__ << std::endl;
}

Car::~Car() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::turnLeft() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::turnRight() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::brake(int speed) {
    std::cout << __FUNCTION__ << ": ";
    try {
        if (speed > currentSpeed_) {
            throw BreakeToHigherSpeedError(std::to_string(currentSpeed_));
        }
        setSpeed(speed);
    } catch (BreakeToHigherSpeedError& speed) {
        std::cerr << speed.what() << "\n";
    }
}
void Car::accelerate(int speed) {
    std::cout << __FUNCTION__ << ": ";
    try {
        if (speed < currentSpeed_ && speed > -20) {
            throw AccelerateToLoweSpeedError(std::to_string(currentSpeed_));
        }
        setSpeed(speed);
    } catch (AccelerateToLoweSpeedError& speed) {
        std::cerr << speed.what() << "\n";
    }
}
int Car::getSpeed() const {
    std::cout << "Car speed = " << currentSpeed_ << std::endl;
    return currentSpeed_;
}
void Car::setSpeed(int speed) {
    try {
        if (speed < -20) {
            throw ToLowSpeedError(std::to_string(speed));
        }
        if (speed > 200) {
            throw ToHighSpeedError(std::to_string(speed));
        }
        currentSpeed_ = speed;
        std::cout << "Car speed = " << currentSpeed_ << std::endl;
    } catch (ToLowSpeedError& speed) {
        std::cerr << speed.what() << "\n";
    } catch (ToHighSpeedError& speed) {
        std::cerr << speed.what() << "\n";
    }
}
