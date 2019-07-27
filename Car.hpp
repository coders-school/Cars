#pragma once

class Car
{
protected:
    int velocity;

public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake(int speed);
    void accelerate (int speed);
    void getSpeed () const;
    void setSpeed(int);
    virtual void feed()=0;
};

