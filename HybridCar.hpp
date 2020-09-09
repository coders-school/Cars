#pragma once

#include "ElectricCar.hpp"
#include "PetrolCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public ElectricCar, public PetrolCar
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();

    //override from Car
    void restore() override { PetrolCar::restore(); ElectricCar::restore(); }
};
