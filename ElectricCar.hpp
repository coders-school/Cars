#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public virtual Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void changeEngine(ElectricEngine* electricEngine);
    void refill() override;

private:
    void charge();
    ElectricEngine* electricEngine_;
};
