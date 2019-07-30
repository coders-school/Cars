#include "Car.hpp"
#include <iostream>

void Car::turnLeft() { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight() { std::cout << __FUNCTION__ << std::endl; }
int Car::getVelocity()
{
	return this->velocity;
}
void Car::brake()
{
	this->velocity = 0;
}
void Car::accelerate(int s)
{

	if (s >= 0)
		this->velocity += s;
	else
		std::cout << "Velocity cannot be negative!" << std::endl;
}
