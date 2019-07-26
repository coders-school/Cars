#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include <iostream>

void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake()         { std::cout << __FUNCTION__ << std::endl; velocity = 0; }
void Car::accelerate(int speed) {
    std::cout << __FUNCTION__ << std::endl;
    velocity += speed;
}

Car::Car(Engine* engine) {
    engine_ = dynamic_cast<ElectricEngine*>(engine);
    if (not engine_)
        engine_ = dynamic_cast<PetrolEngine*>(engine);
    if (not engine_)
        throw std::logic_error("Unknown type of engine");
}

Car::~Car() {
    delete engine_;
    engine_ = nullptr;
}

void Car::changeGear(int gear) {
    if (0 > gear or gear > 6) {
        throw std::runtime_error("Wrong gear definition");
    }
    if (currentGear == "R" and gear != 0) {
        throw std::runtime_error("Potential gearbox damage");
    }
    else {
        currentGear = std::to_string(gear);
    }
}

void Car::changeGear(std::string gear) {
    if (gear != "R") {
        throw std::runtime_error("Wrong gear definition");
    }
    if (currentGear != "0" and gear == "R") {
        throw std::runtime_error("Potential gearbox damage");
    }
    else {
        currentGear = gear;
    }
}

std::string Car::getCurrentGear() {
    return currentGear;
}

int Car::getCurrentSpeed() {
    return velocity;
}
