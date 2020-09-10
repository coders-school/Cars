#pragma once
#include "Engine.hpp"

class Car {
public:
    ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    int getSpeed();
    virtual void restore() = 0;
    virtual void changeEngine(Engine* engine) = 0;

private:
    int speed_;
};
