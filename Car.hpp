#pragma once

class Car
{
public:
    Car();
    virtual ~Car();
    virtual void turnLeft();
    virtual void turnRight();
    virtual void brake();
    virtual void accelerate(int speed);
};
