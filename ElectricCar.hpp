#pragma once

#include "ElectricEngine.hpp"

#include "Car.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void restore() override;

private:
    ElectricEngine* engine_;

    void charge();
};

