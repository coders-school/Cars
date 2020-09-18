#pragma once

#include "Exceptions.hpp"

class Car {
public:
    ~Car();
    virtual void restore() = 0;
    int getSpeed();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);

protected:
    int speed_ = 0;
};
