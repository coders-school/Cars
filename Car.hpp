#pragma once

//#include "Engine.hpp"
#include <memory>

class Car {
public:
    Car();
    ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void restore() = 0;
    
    //virtual void changeEngine(Engine* engine) = 0;
    //virtual int getPower() const = 0;
    int getSpeed() const;

private:
    int speed_ = 0;
};
