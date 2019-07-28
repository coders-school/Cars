#pragma once

class Car
{
public:
    virtual ~Car() = default;
    unsigned getMaxSpeed();
    unsigned getVelocity();
    void printVelocity();
    void turnLeft();
    void turnRight();
    void brake(unsigned amount);
    void accelerate(unsigned amount);
    virtual void feed()=0;
private:
    unsigned velocity=0;
    const unsigned maxSpeed=250;
};

