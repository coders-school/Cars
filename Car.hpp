#pragma once

class Car {
public:
    void turnLeft();
    void turnRight();
    void brake();
    void setSpeed(const int);
    virtual void refill() = 0;
    virtual ~Car() {}

private:
    int speed_{0};
};
