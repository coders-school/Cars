#pragma once

class Car
{
public:
    Car() = default;
    ~Car() = default;

    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void restore() = 0;
};