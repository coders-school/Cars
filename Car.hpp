#pragma once

class Car
{
protected:
    int carSpeed;

public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake(int speed);
    int accelerate (int speed);
    virtual void feed()=0;
    void velocity (int carSpeed);
};

