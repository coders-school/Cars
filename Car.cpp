#include <iostream>
#include "Car.hpp"
#include "carExceptions.hpp"

void Car::turnLeft() {std::cout << __FUNCTION__ << std::endl;}
void Car::turnRight() {std::cout << __FUNCTION__ << std::endl;}
void Car::brake() {std::cout << __FUNCTION__ << std::endl;}
void Car::accelerate(int target) {
    if(target < 0) {throw CarLogicError{"Cannot accelerate to negative values!"};}
    else {std::cout << __FUNCTION__ << std::endl;}
}
