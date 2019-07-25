#include "Car.hpp"
#include <iostream>
Car::Car()
{
	speed = 0;
	velocity = 0;
	slow = 0;
}
Car::~Car() {}
void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::Brake(int _slow)         
{
     slow = _slow;
     std::cout << __FUNCTION__ << std::endl; 
}
void Car::Accelerate(int _speed) 
{
     speed =_speed;
     std::cout << __FUNCTION__ << std::endl; 
}
void Car::Velocity(float _velocity)
{
    _velocity += speed;
    _velocity -= slow;
    velocity = _velocity;
	std::cout << __FUNCTION__ << std::endl;
	std::cout << velocity<< std::endl;

}

