#pragma once
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include <iostream>

class HybridCar : public ElectricCar, public PetrolCar
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();
    void refill() override;
};
