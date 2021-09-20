#pragma once

class Car {
public:
    Car() = default;
    virtual ~Car() = default;

    virtual void turnLeft();
    virtual void turnRight();
    virtual void brake();
    virtual void accelerate(int);
};
