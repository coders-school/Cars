#include "Car.hpp"
#include <iostream>



void Car::turnLeft() { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight() { std::cout << __FUNCTION__ << std::endl; }
void Car::brake() { std::cout << __FUNCTION__ << std::endl; }
void Car::accelerate(int s) { setSpeed(s); }
void Car::setSpeed(int s)
{
	if( s>= 0)
		this->speed_ = s;
	else
		std::cout<<"Predkosc nie moze byc ujemna !"<<std::endl;
}


