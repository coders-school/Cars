#include "Car.hpp"

Car::Car(Engine* engine)
    : engine_(engine)
{

}

Car::~Car() 
{

}

void Car::fillUp() {
    engine_->fillUp();
    std::cout << __FUNCTION__ << std::endl; 
}

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
    if (currentSpeed_ + speed > engine_->getMaxSpeed()) {
        throw Car::InvalidAccelerate("Accross max speed in");
    } else if (currentSpeed_ + speed < engine_->getMaxReverseSpeed()) {
        throw Car::InvalidAccelerate("Accross reverse max speed");
    }
}