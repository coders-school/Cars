#pragma once

#include "Engine.hpp"

class Vehicle {
   public:
    Vehicle(Engine* engine);
    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;
    virtual void brake() = 0;
    virtual void accelerate(int speed) = 0;
};
