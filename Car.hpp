#pragma once

class Car {
public:

    Car();
    virtual ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    bool isStopped();
    int getSpeed();
    // void charge();
    virtual void refill() = 0;

private:
    const int MAX_SPEED_ = 240;
    int currentSpeed_ = 0;
};
