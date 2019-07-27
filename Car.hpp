#pragma once

class Car
{
    public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake();
    void checkAccelerate(int speed);
    void accelerateErr();
    void accelerate(int speed);
    virtual void feed()=0;
};

