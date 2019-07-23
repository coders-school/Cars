#pragma once

#include "Engine.hpp"

class Car
{
protected:
    int velocity = 0;
public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void feed()=0;
    virtual void changeEngine(Engine*)=0;
};

