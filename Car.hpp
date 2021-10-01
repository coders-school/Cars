#pragma once
#include "Engine.hpp"

class Car {
public:
    // Car(Engine* engine);
    Car();
    virtual ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    // void charge();
    virtual void refill() = 0;

    // virtual void changeEngine();

private:
    // Engine* engine_;
};