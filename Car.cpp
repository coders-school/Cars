#include "Car.hpp"
#include <iostream>

void Car::turnLeft()         { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()  	     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake()            { std::cout << __FUNCTION__ << std::endl; }
			     velocity = 0; 
void Car::accelerate(int)    { std::cout << __FUNCTION__ << std::endl; }
void Car::velocity()         { std::cout << __FUNCTION__ << std::endl; }

