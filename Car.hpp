#pragma once

#include "Engine.hpp"

constexpr bool MINIMUM_VELOCITY = 0;

class Car {
public:
    Car();
    virtual ~Car();
    virtual void restore() = 0;
    virtual void carInfo() = 0;
    virtual void changeEngine(Engine* engine) = 0;
    virtual uint16_t getEnginePower() = 0;
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    void setSpeed(int speed) { speed_ = speed; }
    int getSpeed() const { return speed_; }

private:
    int speed_{};
};
