#pragma once

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

#include <iostream>

class HybridCar : public ElectricCar,
                  public PetrolCar
{
  public:
    HybridCar(int maxSpeed,
              int maxReverseSpeed,
              const PetrolEngine& petrolEng,
              const ElectricEngine& electricEng);
    HybridCar(int maxSpeed,
              int maxReverseSpeed,
              PetrolEngine&& petrolEng,
              ElectricEngine&& electricEng);
    ~HybridCar() override;
    void refill() override;
    void replaceElectricEngine(ElectricEngine&& newEngine);
    void replacePetrolEngine(PetrolEngine&& newEngine);
};
