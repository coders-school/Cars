#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine *engine);
    ~ElectricCar();
    void restore() override;

private:
    void charge();

    ElectricEngine *electricEngine_;
};
