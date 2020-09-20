#pragma once

#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "ElectricCar.hpp"
#include "PetrolCar.hpp"

class HybridCar : public virtual  ElectricCar, public virtual  PetrolCar 
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    virtual ~HybridCar();
};

