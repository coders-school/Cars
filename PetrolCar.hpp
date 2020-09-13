#pragma once
#include "Car.hpp"
#include "PetrolEngine.hpp"
#include <memory>
class PetrolCar : virtual public Car {
public:
  PetrolCar(std::unique_ptr<PetrolEngine> engine);
  ~PetrolCar();
  void refuel();

private:
 std::unique_ptr<PetrolEngine> engine_;
};
