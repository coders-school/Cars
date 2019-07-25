#pragma once

class Car
{
protected:
    unsigned velocity=0;
    const unsigned maxSpeed=250;

public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(unsigned amount);
    virtual void feed()=0;
};

