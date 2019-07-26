#pragma once
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class Car
{
public:
    virtual ~Car() = default;
    int velocity = 0;
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int) ;
    virtual void addEnergy()=0;
	void setSpeed(int);
protected:
	int speed_;
	ElectricEngine *electricEngine_;
	PetrolEngine *petrolEngine_;
};
