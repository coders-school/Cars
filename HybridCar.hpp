#pragma once

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public ElectricCar,
                  public PetrolCar
{
  public:
    HybridCar(const PetrolEngine& petrolEng, ElectricEngine& electricEng);
    HybridCar(PetrolEngine&& petrolEng, ElectricEngine&& electricEng);
    ~HybridCar() override;
    void refill()override;
};
