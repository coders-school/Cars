#pragma once
#include "Engine.hpp"

constexpr int minSpeed = 0;
constexpr int maxSpeed = 300;

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
