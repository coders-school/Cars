#include "Car.hpp"
#include"Exceptions.hpp"
#include <iostream>

    void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
    void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
    void Car::brake()         { std::cout << __FUNCTION__ << std::endl; }
    void Car::accelerate(int) { std::cout << __FUNCTION__ << std::endl; }
    void Car::changeEngine(int, int){};

