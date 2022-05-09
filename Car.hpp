#pragma once
#include <iostream>
#include <memory>
#include <exception>
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class Car
{
public:
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void refill() = 0;
    virtual void changeEngine(std::unique_ptr<ElectricEngine> engine) = 0;
    virtual void changeEngine(std::unique_ptr<PetrolEngine> engine) = 0;
    virtual ~Car(){}

    protected:
    float currentSpeed_{0};
};