#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public virtual Car {
public:
    ElectricCar(ElectricEngine* engine);

    ~ElectricCar() override;

    void changeEngine(ElectricEngine* ee) override;

    void refill() override;

private:
    void charge();

    ElectricEngine* engine_;
};
