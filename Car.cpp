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

