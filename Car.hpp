#pragma once

class Car {
public:
    ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void restore() = 0;
};