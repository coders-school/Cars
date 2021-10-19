#include "Car.hpp"
#include <iostream>

Car::Car() {} 
// Car::Car(Engine* engine)
//     : engine_(engine)
// {
//     std::cout << __FUNCTION__ << std::endl;
// }

Car::~Car()       { std::cout << __FUNCTION__ << std::endl; }
void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake()         { std::cout << __FUNCTION__ << std::endl; }
void Car::accelerate(int) { std::cout << __FUNCTION__ << std::endl; }