#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : public virtual Car
{
protected:
    void charge();
    ElectricEngine* engine_;
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar() override;

    void feed() override;
    void changeEngine(Engine* engine) override;
};

