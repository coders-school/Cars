#pragma once

class Car
{
    protected:
    int velocity;
public:
    Car();
    virtual ~Car();
    void turnLeft();
    void turnRight();
    void brake(int);
    void accelerate(int);
    virtual void feed()=0;
};

