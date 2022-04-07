#pragma once
#include "ElectricEngine.hpp"
#include "ElectricCar.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public ElectricCar, public PetrolCar
{
public:
    HybridCar(PetrolEngine *petrolEng, ElectricEngine *electricEng);
    ~HybridCar();
    void refill() override;
    void changeEngine(Engine *engine) override;
};
