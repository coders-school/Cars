#pragma once

class Car
{
protected:
    //int carSpeed;
    int velocity;

public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake(int speed);
    void accelerate (int speed);
    virtual void feed()=0;
   // void velocity (int carSpeed);
    void getSpeed ();
    void setSpeed(int);
};

