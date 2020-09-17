#pragma once

#include "Engine.hpp"
#include "Errors.hpp"

class Car {
public:
    Car();
    virtual ~Car();

    void turnLeft();
    void turnRight();
    void brake(int speed);
    void accelerate(int speed);
    void setSpeed(int speed);
    int getSpeed() const;

    virtual void restore() = 0;
    virtual void changeEngine(Engine* engine) = 0;
    virtual void setGear(int gear) = 0;

private:
    int currentSpeed_ = 0;
    const int maxReverseSpeed = -20;
    const int maxSpeed = 200;
};
