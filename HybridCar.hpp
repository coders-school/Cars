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

  //ElectricEngine *getElectricEngineData() const;
  //std::unique_ptr<ElectricEngine> pullOutElectricEngine();
  //void putInElectricEngine(std::unique_ptr<ElectricEngine> newEngine);
  
/*   PetrolEngine *getPetrolEngineData() const;
  std::unique_ptr<PetrolEngine> pullOutPetrolEngine();
  void putInPetrolEngine(std::unique_ptr<PetrolEngine> newEngine); */

  void restore() override;
  void accelerate(int requiredSpeed) override;
};
