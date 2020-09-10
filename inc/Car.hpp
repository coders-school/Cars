#pragma once

#include "Engine.hpp"

class Car {
public:
    Car();
    virtual ~Car();
    
    virtual void restore() = 0;
    virtual void changeEngine(Engine* engine) = 0;
    virtual int getEnginePower() const = 0;

    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);

    int getSpeed() const { return speed_; }

protected:
    int speed_;
};
