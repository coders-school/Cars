#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "Engine.hpp"

class ElectricCar : public Car
{
public:
    ElectricCar(Engine* engine);
    ~ElectricCar();
    void accelerate(int speed);
};

