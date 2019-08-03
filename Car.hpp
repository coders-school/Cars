#pragma once

#include "Gear.hpp"

class Car
{
public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int acceleration);
    void changeGear(Gear gear);
    virtual void feed()=0;

    Gear getGear() const;
    int getVelocity() const;

private:
    int velocity {};
    Gear currentGear {Gear::_N};
};