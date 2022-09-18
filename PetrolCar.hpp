#pragma once

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car
{
  public:
    PetrolCar(int maxSpeed, int maxReverseSpeed, const PetrolEngine& engine);
    PetrolCar(int maxSpeed, int maxReverseSpeed, PetrolEngine&& engine);
    ~PetrolCar() override;
    void refill() override;
    void replaceEngine(PetrolEngine&& newEngine);

  protected:
    void refuel();

    PetrolEngine engine_;
};
