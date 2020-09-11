#pragma once

class Car {
public:
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    int getSpeed() const { return currentSpeed_; };

    virtual void restore() = 0;

private:
    int currentSpeed_ = 0;
};
