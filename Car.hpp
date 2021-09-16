#pragma once

class Car {
public:
    virtual ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    int getSpeed() const;
    virtual void refill() = 0;

private:
    int speed_;
};
