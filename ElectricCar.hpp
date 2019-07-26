#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : public virtual Car
{
protected:
    void charge();
public:
    explicit ElectricCar(Engine *engine);

    void feed() override;
    void changeEngine(Engine* engine) override;
};

