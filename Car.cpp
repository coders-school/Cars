#include "Car.hpp"
#include <iostream>
#include <cassert>
Car::Car()
{
	velocity = 0;
}
Car::~Car() {}
void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake(int speed)
{
	if(speed<0) { std::cout << "Cannot brake with vegative value!" << std::endl; }
	else if(speed==0) { std::cout << "Maintaining current speed" << std::endl; }
	else if(speed>0) 
	{
		velocity -= speed;
		std::cout << __FUNCTION__ << std::endl;
		std::cout << "Current speed: " << velocity << std::endl;
	}
	assert(velocity>=0); std::cout << "You did not brake too hard" << std::endl;
}
void Car::accelerate(int speed)
{
	if (speed < 0) std::cout << "Cannot brake with vegative value!" << std::endl;
	else if (speed == 0) std::cout << "Maintaining current speed" << std::endl;
	else if (speed > 0)
	{
	velocity += speed;
	std::cout << __FUNCTION__ << std::endl;
	std::cout << "Current speed: " << velocity << std::endl;
	}
}


