#pragma once

class Car
{
protected:
    int velocity=0;

public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int amount);
    virtual void feed()=0;
};

