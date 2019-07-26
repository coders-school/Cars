#include "Car.hpp"
#include <iostream>
Car::Car()
{
	velocity = 0;
}
Car::~Car() {}
void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake(int speed)
{
	velocity -= speed;
	std::cout << __FUNCTION__ << std::endl;
	std::cout << "Aktualna predkosc" << velocity << std::endl;
}
void Car::accelerate(int speed)
{
	velocity += speed;
	std::cout << __FUNCTION__ << std::endl;
	std::cout << "Aktualna predkosc" << velocity << std::endl;
}


