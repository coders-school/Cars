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
}
void Car::accelerate(int speed) {
    std::cout << __FUNCTION__ << std::endl;

    auto validationSpeed =[](const int speed) { return speed >= 0 && speed <= 180; };
    if (validationSpeed(speed)) {
        speed_ = speed;
    } else {
        throw std::range_error("Speed out of range!!!!");
    }
}
double Car::getSpeed() const {
    return speed_;
}

void Car::changeEngine(std::unique_ptr<PetrolEngine> pe) {
    throw InvalidParameter("It is not petrol engine!!!");
}

void Car::changeEngine(std::unique_ptr<ElectricEngine> ee) {
    throw InvalidParameter("It is not electrical engine!!!");
}
