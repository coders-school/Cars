#pragma once

class Car {
public:
    Car();
    virtual ~Car();
    void turnLeft();
    void turnRight();
    void brake(int speed);
    void accelerate(int speed);
    virtual void restore() = 0;
    int getSpeed() const;
    void setSpeed(int speed);

protected:
    int currentSpeed_ = 50;
};
