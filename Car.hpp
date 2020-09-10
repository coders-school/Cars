#pragma once

#include <cstddef>

#include "Engine.hpp"
class Car {
public:
    virtual void turnLeft();
    virtual void turnRight();
    virtual void brake();
    virtual void refill() = 0;
    virtual void changeEngine(Engine*) = 0;
    virtual int getEnginePower() = 0;
    virtual void accelerate(int speed);
    virtual ~Car(){};

protected:
    size_t currentSpeed_{};
};
