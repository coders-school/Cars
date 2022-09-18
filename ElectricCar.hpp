#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"
class ElectricCar : virtual public Car
{
  public:
    ElectricCar(int maxSpeed, int maxReverseSpeed, const ElectricEngine& engine);
    ElectricCar(int maxSpeed, int maxReverseSpeed, ElectricEngine&& engine);
    ~ElectricCar() override;
    void refill() override;
    void replaceEngine(ElectricEngine&& newEngine);

  protected:
    void charge();

    ElectricEngine engine_;
};
