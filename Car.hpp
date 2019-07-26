#pragma once

class Car
{
public:
    virtual ~Car() = default;
    int getVelocity();
    void printVelocity();
    void turnLeft();
    void turnRight();
    void brake(int amount);
    void accelerate(int amount);
    virtual void feed()=0;
private:
    int velocity=0;
    const unsigned maxSpeed=250;
};

