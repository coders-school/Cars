#pragma once

class Car
{
public:
    ~Car();
    virtual void restore() = 0;
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
};
