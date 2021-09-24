#pragma once
#include <iostream>
#include <memory>
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class Car {
public:
    Car();
    virtual ~Car();

    virtual void turnLeft();
    virtual void turnRight();
    virtual void brake();
    virtual void accelerate(int);
    virtual void powerSuply() = 0;
   
    virtual void changeEngine(int, float, int = 0, int = 0, int = 0) = 0;
};
