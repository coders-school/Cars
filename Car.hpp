#pragma once
#include "Engine.hpp"

class Car
{
public:
    Car();
    //Car(Engine* engine);
    ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);

    //Engine* engine_;
};