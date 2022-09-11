#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"
class ElectricCar : virtual public Car
{
  public:
    ElectricCar(const ElectricEngine& engine);
    ElectricCar(ElectricEngine&& engine);
    ~ElectricCar() override;
    void refill() override;

  private:
    void charge();

    ElectricEngine engine_;
};
