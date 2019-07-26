#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : public virtual Car
{
protected:
    void charge();
    ElectricEngine* engine_;
public:
    ElectricCar(ElectricEngine* engine, int vmax);
    ~ElectricCar();
    void feed() override;
    void changeElectricEngine(ElectricEngine* engine);
};

