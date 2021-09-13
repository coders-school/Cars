#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#pragma once
#include "PetrolEngine.hpp"
class HybridCar : public PetrolCar, public ElectricCar {
   public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();
    void restore() override;
    
};
