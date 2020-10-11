#pragma once

#include "PetrolCar.hpp"
#include "ElectricCar.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEngine, std::unique_ptr<ElectricEngine> electricEngine);
    ~HybridCar();
    void restore() override;
    void changeEngine(std::unique_ptr<PetrolEngine> newEngine);
    void changeEngine(std::unique_ptr<ElectricEngine> newEngine);
};
