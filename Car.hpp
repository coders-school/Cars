#pragma once

class Car
{
public:
    int velocity =0;
    int Vmax;
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake(int time);
    void accelerate(int speed);
    virtual void feed()=0;
};

