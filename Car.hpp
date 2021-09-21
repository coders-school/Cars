#pragma once
#include <memory>
#include "PetrolEngine.hpp"
#include "ElectricEngine.hpp"
class Car {
public:
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void refill() = 0;
    virtual ~Car(){};
    // virtual void changeEngine(std::unique_ptr<PetrolEngine> pe);
    // virtual void changeEngine(ElectricEngine* ee) = 0;
private:
    double speed_{0.0};
   
};
