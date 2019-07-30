#pragma once
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class Car
{
public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int s) ;
    virtual void addEnergy()=0;
    virtual int getVelocity();
protected:
	int velocity = 0;
};
