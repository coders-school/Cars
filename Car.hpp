#pragma once

class Car {
public:
    Car(int maxSpeed = 200, int currentSpeed = 0) : maxSpeed_(maxSpeed), currentSpeed_(currentSpeed) {};
    ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void restore() = 0;

    int getCurrentSpeed() const { return currentSpeed_; }
    int getMaxSpeed() const { return maxSpeed_; }
private:
    int maxSpeed_;
    int currentSpeed_;
};
