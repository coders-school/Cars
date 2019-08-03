#pragma once

#include "Gear.hpp"

class Car
{
public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake();
    void checkAccelerate(int speed);
    void accelerateErr();
    void accelerate(int speed);
    void changeGear(Gear gear);
    virtual void feed()=0;

private:
    int velocity;
    Gear currentGear;
};