#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : public virtual Car
{
protected:
    void charge();
    ElectricEngine* engine_;
public:
    void feed() override;
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
};






