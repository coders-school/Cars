#pragma once

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEngine, std::unique_ptr<ElectricEngine> electricEngine);
    ~HybridCar();

    void changeEngine(std::unique_ptr<ElectricEngine> electricEngine, std::unique_ptr<PetrolEngine> petrolEngine);
    void restore() override;
};
