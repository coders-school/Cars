#pragma once
#include "Car.hpp"
#include "PetrolEngine.hpp"
#include <memory>
class PetrolCar : virtual public Car {
public:
  PetrolCar(std::unique_ptr<PetrolEngine> engine);
  ~PetrolCar();

  void restore() override;
  void accelerate(int a) override;
  PetrolEngine *getPetrolEngineData() const;
  std::unique_ptr<PetrolEngine> pullOutPetrolEngine();
  void putInPetrolEngine(std::unique_ptr<PetrolEngine> newEngine);

private:
  std::unique_ptr<PetrolEngine> engine_;
  void refuel();
};
