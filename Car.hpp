#pragma once
#include <iostream>
#include "Engine.hpp"

class Car
{
public:
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int);
    virtual void refill() = 0;
    virtual void changeEngine(Engine* engine) = 0;
    virtual ~Car(){}
};