#pragma once

#include "Engine.hpp"
#include <string>

class Car
{
protected:
    int velocity = 0;
    Engine* engine_;
    std::string currentGear = "0";
public:
    explicit Car(Engine*);

    Car() = default;

    ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void feed()=0;
    virtual void changeEngine(Engine*)=0;
    void changeGear(int);
    void changeGear(std::string);
    std::string getCurrentGear();
    int getCurrentSpeed();
};

