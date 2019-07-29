#include <iostream>
#include <sstream>

#include "Exceptions.hpp"
#include "Car.hpp"



void Car::turnRight()
{
    std::cout << __FUNCTION__ << std::endl; 
}

void Car::brake(int speed)
{

    std::ostringstream oos;
	if (speed > 0)
	{
		oos << "Incorrect value. Decceleration speed need to be negative: ";
		throw IncorrectVelocity(oos.str());
	}
    if(speed < - currentSpeed_)
	{
        oos << "Incorrect value. Decceleration should be between: " << 0 << " and " <<  - currentSpeed_;
        throw IncorrectVelocity(oos.str());
    }

    if(currentSpeed_ + speed < 0 ) {
		currentSpeed_ = 0;
    }
    else {
		currentSpeed_ += speed;
    }

	std::cout << __FUNCTION__ << std::endl;
}

void Car::turnLeft()
{
    std::cout << __FUNCTION__ << std::endl; 
}

void Car::accelerate(int speed)
{
    std::ostringstream oos;
	if (speed < 0) {
		oos << "Acceleration can't be negative";
		throw IncorrectVelocity(oos.str());
	}
    else if(speed > (maxSpeed_ - currentSpeed_) ) {
        oos << "Acceleration can't be grater than: " << (maxSpeed_ - currentSpeed_);
        throw IncorrectVelocity(oos.str());
    }

    if(currentSpeed_ + speed > maxSpeed_) {
		currentSpeed_ = maxSpeed_;
    }
    else {
		currentSpeed_ += speed;
    }

	std::cout << __FUNCTION__ << std::endl;
}

int Car::getCurrentSpeed() const
{
	std::cout << __FUNCTION__ << std::endl;
    return currentSpeed_;
}

int Car::getMaxSpeed() const
{
	std::cout << __FUNCTION__ << std::endl;
	return maxSpeed_;
}