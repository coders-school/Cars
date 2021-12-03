#include "Car.hpp"
#include <iostream>

void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }

void Car::brake() {
     speed_ = 0.0; 
}
void Car::accelerate(int speed) { 
    if(speed < 0.0) {
        throw std::range_error("Speed can't be below zero!");
    }
    if(speed > maxSpeed) {
        throw std::range_error("Speed can't be over 300.0 km/h!");
    }
    speed_ = speed;
}
void Car::changeEngine(std::unique_ptr<PetrolEngine>) {
    throw std::invalid_argument("This is not a petrol car!");
}
void Car::changeEngine(std::unique_ptr<ElectricEngine>) {
    throw std::invalid_argument("This is not an electric car!");
}
