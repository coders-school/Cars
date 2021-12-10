#pragma once

class Car {
public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    int getSpeed() const;
    virtual void refill() = 0;
protected:
    int speed_{0};
};
