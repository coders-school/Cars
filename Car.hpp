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

    virtual void restore() = 0;
    virtual void changeEngine(Engine* engine) = 0;

    int getSpeed() const;

protected:
    int speed_ = 0;
    int maxSpeed_ = 200;
};