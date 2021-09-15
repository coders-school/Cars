#pragma once
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
private:
    PetrolEngine* petrolEngine_;
    ElectricEngine* electricEngine_;
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();
};
