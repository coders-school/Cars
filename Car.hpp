#pragma once
#include <memory>
#include "InvalidsError.hpp"
#include "PetrolEngine.hpp"

class Car {
public:
    virtual ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    void showSpeed();
    int getSpeed();
    virtual void restore() = 0;
    virtual void getInfoEngine() = 0;

protected:
    int speed_ = 0;
};