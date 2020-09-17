#pragma once
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include <memory>

class HybridCar : public PetrolCar, public ElectricCar {

public:
  HybridCar(std::unique_ptr<PetrolEngine> petrolEng,
            std::unique_ptr<ElectricEngine> electricEng);
  ~HybridCar();
  PetrolEngine *getPetrolEngine() const;
  void restore() override;
  void accelerate(int requiredSpeed) override;
};
