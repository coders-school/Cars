#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();

    //override from Car
    void restore() override;

private:
    ElectricEngine* engine_;
    void charge();
};
