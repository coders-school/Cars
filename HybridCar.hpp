#pragma once
#include "ElectricCar.hpp"
#include "PetrolCar.hpp"

class HybridCar : public ElectricCar, public PetrolCar {
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEngine, std::unique_ptr<ElectricEngine> electricEngine);
    ~HybridCar() override;
};