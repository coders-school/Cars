#pragma once

#include "Engine.hpp"

#include <iostream>

class Car {
public:
    Car(Engine* engine);
    virtual ~Car();
    void accelerate(int);
    void fillUp();
    void turnLeft();
    void turnRight();
    void brake();

protected:
    Engine* engine_;
};
