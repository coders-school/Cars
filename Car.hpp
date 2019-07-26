#pragma once

class Car
{
public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(unsigned amount);
    virtual void feed()=0;
private:
    unsigned velocity=0;
    const unsigned maxSpeed=250;
};

