#pragma once

class Car {
    public:

    Car() = default;
    virtual ~Car() = default;

    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;
    virtual void brake() = 0;
    virtual void accelerate(int speed) = 0;
};