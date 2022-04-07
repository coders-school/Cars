#pragma once
#include "Car.hpp"
#include "Engine.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine *engine);
    ~ElectricCar();
    void changeEngine(Engine *engine) override;
    void refill() override;

protected:
    void charge();
    Engine *engine_;
};
