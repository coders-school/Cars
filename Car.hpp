#pragma once

class Car
{
public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void velocity();
    void brake();
    void accelerate(int speed);
    virtual void feed()=0;
};

