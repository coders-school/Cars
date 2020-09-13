#pragma once

class Car
{
public:
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void restore() = 0;
    int getSpeed() const { return speed_; }

private:
    int speed_{};
};
