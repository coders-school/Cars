#pragma once
#include <memory>

class PetrolEngine;
class ElectricEngine;

class Car {
public:
    void turnLeft();
    void turnRight();
    void brake();
    void setSpeed(const int);
    size_t getSpeed();
    virtual void refill() = 0;
    virtual void changeEngine(std::unique_ptr<PetrolEngine>);
    virtual void changeEngine(std::unique_ptr<ElectricEngine>);
    virtual ~Car() {}

private:
    int speed_{0};
};
