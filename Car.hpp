#pragma once

class Car
{
public:

    virtual void turnLeft();
    virtual void turnRight();
    virtual void brake();
    virtual void accelerate(int) ;
    virtual void addEnergy()=0;
};
