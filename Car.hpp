#pragma once

class Car {
public:
    void turnLeft();
    void turnRight();
    void brake();
    void setSpeed(const int);
    virtual void refill() = 0;
    // virtual void changeGear(int) = 0;  // consider throwing exception when trying to change gear to car or electric car
    virtual ~Car() {}

private:
    int speed_{0};
};
