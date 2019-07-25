#pragma once

class Car
{
public:
    int velocity = 0;
    virtual ~Car() = default;

    virtual void turnLeft();
    virtual void turnRight();
    virtual void brake();
    virtual void accelerate(int);
    virtual void addEnergy() = 0;
};
