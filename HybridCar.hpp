#pragma once
#include "ElectricCar.hpp"
#include "PetrolCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public PetrolCar, public ElectricCar
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar()override;
    void refill()override;
};

