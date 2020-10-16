#pragma once

#include <memory>

class Car {
public:
    Car();
    ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void restore() = 0;
    int getSpeed() const;

private:
    int speed_ = 0;
};
