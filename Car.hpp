#pragma once
#include <cstddef>

class Car {
public:
    Car() = default;
    ~Car() = default;

    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void restore() = 0;

protected:
    size_t speed_ = 0;
};