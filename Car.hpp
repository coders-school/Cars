#pragma once

class Car {
public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void accelerate(int speed);
    void decelerate(int speed);
    void brake();
    virtual void restore() = 0;

protected:
    int speed_ = 0;
};
