#pragma once

#include <memory>

class PetrolEngine;
class ElectricEngine;

class Car {
public:
    virtual ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    int getSpeed() const;
    virtual void refill() = 0;
    virtual void changeEngine(std::unique_ptr<PetrolEngine> engine) = 0;
    virtual void changeEngine(std::unique_ptr<ElectricEngine> engine) = 0;

private:
    int speed_;
};
