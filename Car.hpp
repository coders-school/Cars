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
    void showSpeed() const;
    int getSpeed() const;
    virtual void restore() = 0;
    virtual void printInfoEngine() const = 0;

protected:
    int speed_ = 0;
};