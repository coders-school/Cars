#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine *engine);
    ElectricCar() = default;
    ~ElectricCar();

    void addEnergy() override;
    ElectricEngine *changeEngine(int, int);
    void accelerate(int moreSpeed);
    void brake();

protected:
    void charge();

private:
    ElectricEngine *electricEngine_;
};
