#pragma once

#include "Engine.hpp"

class Vehicle {
    Engine* engine_;
   public:
    Vehicle(Engine* engine);
    virtual ~Vehicle();
    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;
    virtual void brake() = 0;
    virtual void accelerate(int speed) = 0;
};
