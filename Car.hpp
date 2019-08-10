#pragma once

class Car
{
protected:
    int velocity=0;
public:
    virtual ~Car() = default;
    virtual void feed() = 0;
    void turnLeft();
    void turnRight();
    void brake();
    int getVelocity();
    void accelerate(int speed);
     
};

