#pragma once

#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"

class HybridCar : public PetrolCar, public ElectricCar
{
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();

    void restore() override;
};

