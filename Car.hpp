#pragma once

class Car
{
    protected:
    int velocity;
    int currentGear;
public:
    Car();
    virtual ~Car();
    void turnLeft();
    void turnRight();
    void brake(int);
    void accelerate(int);
    virtual void feed()=0;
    void changeGear(int);
};

struct GearChangeFailure
{};
