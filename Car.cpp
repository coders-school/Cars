#include "Car.hpp"
#include <iostream>

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
    if (speed < 0) {
        std::cout << "Incorred value of acceleration, speed parameter: " << speed
                  << " should be non-negtive number." << std::endl;
    } else {
        std::cout << __FUNCTION__ << std::endl;
        this->currentSpeed_ = speed;
    }
}
