#pragma once
#include "Engine.hpp"

class Car {
public:
    Car();
    virtual ~Car();

    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
};