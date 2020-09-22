#pragma once

#include "ElectricCar.hpp"
#include "PetrolCar.hpp"

class HybridCar : public PetrolCar, public ElectricCar
{
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();
    void restore() override;

    void changeEngine(std::unique_ptr<PetrolEngine> petrolEngine);
    void changeEngine(std::unique_ptr<ElectricEngine> electricEngine);
};
