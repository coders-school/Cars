#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine *engine)
	: electricEngine_(engine)
{
	std::cout << __FUNCTION__ << std::endl;
}
ElectricCar::~ElectricCar()
{
	delete electricEngine_;
	std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::addEnergy() { charge(); }
void ElectricCar::charge() { std::cout << __FUNCTION__ << std::endl; }
ElectricEngine *ElectricCar::changeEngine(int pow, int bat)
{
	if (speed_ == 0)
	{
		delete this->electricEngine_;
		this->electricEngine_ = new ElectricEngine(pow, bat);
		return this->electricEngine_;
	}
	else
		std::cout << "Operacja niemozliwa" << std::endl;
}

void ElectricCar::accelerate(int moreSpeed)
{
	velocity += moreSpeed;
	std::cout << "Current velocity " << velocity << std::endl;
}
void ElectricCar::brake() { velocity = 0; }
