#pragma once
#include "ExceptionCar.hpp"

class Car
{
public:
    Car();
    Car(int maxSpeed);
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    int getVelocity() const;
    virtual void feed()=0;
private:
    int maxSpeed_;
    int velocity_;
};

