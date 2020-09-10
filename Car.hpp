#pragma once

#include <cstddef>
class Car {
public:
    virtual void turnLeft();
    virtual void turnRight();
    virtual void brake();
    virtual void refill() = 0;
    virtual void accelerate(int speed);
    virtual ~Car(){};

protected:
    size_t currentSpeed_{};
};