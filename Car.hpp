#pragma once

#include <memory>

#include "Engine.hpp"

constexpr int noSpeed = 0;

class Car {
protected:
    int speed_;
    
public:
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    int getSpeed() const { return speed_; }
    virtual void restore() = 0;
};
