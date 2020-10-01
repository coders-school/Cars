#pragma once

#include "ICar.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public ICar
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void turnLeft() const override;
    void turnRight() const override;
    void brake() const override;
    void accelerate(int speed) const override;
    void charge();

    ElectricEngine* engine_;
};


