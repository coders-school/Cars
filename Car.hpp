#pragma once

#include <memory>

#include "Exeptions.hpp"
#include "PetrolEngine.hpp"
#include "ElectricEngine.hpp"

class Car {
public:
    virtual ~Car(){};
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void refill() = 0;
    virtual void changeEngine(std::unique_ptr<PetrolEngine> pe);
    virtual void changeEngine(std::unique_ptr<ElectricEngine> ee);
    double getSpeed() const;
private:
    double speed_{0.0};
};
