#pragma once
#include "Engine.hpp"

class Car {
public:
    ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    void decelerate(int speed);
    int getSpeed();
    virtual void restore() = 0;

protected:
    int speed_ = 0;
};
