#include "Car.hpp"
#include <iostream>

void Car::turnLeft() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::turnRight() {
    std::cout << __FUNCTION__ << std::endl;
}
void Car::brake() {
    speed_ = 0;
}
void Car::accelerate(int speed) {
    if (speedIsValid(speed)) {
        std::cout << __FUNCTION__ << std::endl;
        speed_ = speed;
    } else {
        throw InvalidSpeed("Speed out of range!!!");
    }
}

bool Car::speedIsValid(const int& speed) {
    return speed >= 0 && speed <= 200;
}

void Car::changeEngine(std::unique_ptr<PetrolEngine> petrolEngine) {
    throw WrongEngine("It is not a petrol car!!!");
}

void Car::changeEngine(std::unique_ptr<ElectricEngine> electricEngine) {
    throw WrongEngine("It is not an electric car!!!");
}