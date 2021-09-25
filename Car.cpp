#include <iostream>

#include "Car.hpp"
#include "Exeptions.hpp"

void Car::turnLeft() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::turnRight() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::brake() {
    std::cout << __FUNCTION__ << std::endl;
    speed_ = 0;
}
void Car::accelerate(int speed) {
    std::cout << __FUNCTION__ << std::endl;

    auto validationSpeed = [](const int speed) { return speed >= 0 && speed <= 180; };
    if (!validationSpeed(speed)) {
        throw InvalidParameter("Speed out of range!!!!");
    }
    speed_ = speed;
}
double Car::getSpeed() const {
    std::cout << __FUNCTION__ << std::endl;
    std::cout << speed_ << '\n';
    return speed_;
}

void Car::changeEngine(std::unique_ptr<PetrolEngine>) {
    throw InvalidParameter("It is not petrol engine!!!");
}

void Car::changeEngine(std::unique_ptr<ElectricEngine>) {
    throw InvalidParameter("It is not electrical engine!!!");
}
