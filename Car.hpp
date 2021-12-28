#pragma once

class Car {
public:
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int);
    virtual void refill() = 0;
    // virtual void changeGear(int) = 0;
    virtual ~Car() {}
};
