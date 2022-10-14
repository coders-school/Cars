#pragma once

#include "CarBehaviors.hpp"

class Car : public virtual ChangeEngine {
public:
    void turnLeft();

    void turnRight();

    void brake();

    void accelerate(int speed);

    virtual void changeEngine(ElectricEngine* engine);

    virtual void changeEngine(PetrolEngine* engine);

public:

    virtual void refill() = 0;

    virtual ~Car() {}
};
