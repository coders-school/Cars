#pragma once
#include <iostream>
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public ElectricCar, public PetrolCar {
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEngine, std::unique_ptr<ElectricEngine> electricEngine);
    ~HybridCar();
    void refill() override;
};
