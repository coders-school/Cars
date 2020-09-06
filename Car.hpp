#pragma once

class Car {
public:
    virtual ~Car();
    Car();
    virtual void turnLeft();
    virtual void turnRight();
    virtual void brake();
    virtual void accelerate(int speed);
};
