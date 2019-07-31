#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : public virtual Car
{
protected:
    void charge();
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void feed() override;

    ElectricEngine* engine_;
    void set_electric_engine(int, int);
};

