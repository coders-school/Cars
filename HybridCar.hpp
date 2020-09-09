#pragma once

#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"

class HybridCar : public PetrolCar, public ElectricCar
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();

    void restore() override;
};

