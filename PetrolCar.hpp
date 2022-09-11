#pragma once

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car
{
  public:
    PetrolCar(const PetrolEngine& engine);
    PetrolCar(PetrolEngine&& engine);
    ~PetrolCar() override;
    void refill() override;

  private:
    void refuel();

    PetrolEngine engine_;
};
