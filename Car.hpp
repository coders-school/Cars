#pragma once

#include <cstddef>

class PetrolEngine;
class ElectricEngine;

constexpr size_t MIN_CAPACITY = 0;
constexpr size_t MAX_CAPACITY = 100;

class Car
{
public:
    Car();
    virtual ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerateTo(int speed);
    int getSpeed();
    virtual void restore() = 0;
    virtual void changeGear(int gear) = 0;
    virtual void setEngine(PetrolEngine*) = 0;
    virtual void setEngine(ElectricEngine*) = 0;
    virtual void setEngine(PetrolEngine*, ElectricEngine*) = 0;

private:
    int speed_;
};
