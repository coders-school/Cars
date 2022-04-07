#pragma once
#include <iostream>
#include <memory>
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class Car
{
public:
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int);
    virtual void refill() = 0;
    virtual void changeEngine(std::unique_ptr<ElectricEngine> engine);
    virtual void changeEngine(std::unique_ptr<PetrolEngine> engine);
    virtual ~Car(){}
};