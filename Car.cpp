#include "Car.hpp"

Car::Car(Engine* engine)
    : engine_(engine)
{

}

Car::~Car() 
{

}

void Car::accelerate(int speed) {
    std::cout << speed;
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