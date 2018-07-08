#pragma once

class Car
{
public:
    virtual void turnLeft();
    virtual void turnRight();
    virtual void brake();
    virtual void accelerate(int speed);
    virtual void refill() = 0;
    virtual ~Car() {}
};

