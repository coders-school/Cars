#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : public Car
{
public:
    ElectricCar(ElectricEngine* engine)
        : engine_(engine)
    {}
    ~ElectricCar() {}
    void charge() {}

    ElectricEngine* engine_;
};

