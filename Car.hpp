#pragma once

class Car
{
    protected:
    int slow;
    int speed;
    float velocity;
public:
    Car();
    virtual ~Car();
    void turnLeft();
    void turnRight();
    void Brake(int);
    void Accelerate(int);
    virtual void feed()=0;
    void Velocity(float);
};

