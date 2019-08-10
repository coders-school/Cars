#pragma once
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "ElectricCar.hpp"
#include "PetrolCar.hpp"
class HybridCar : public PetrolCar, public ElectricCar
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();
    void feed() override;
    void accelerate(int value)
    {
        PetrolCar::accelerate(value);
    }

    void brake()
    {
        velocity=0;
    }
};

