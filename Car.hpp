#pragma once

class Car
{
public:
    Car();
    //~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void refill() = 0;
    virtual ~Car() {};
    // virtual void charge() = 0;
    // virtual void refuel() = 0;
};