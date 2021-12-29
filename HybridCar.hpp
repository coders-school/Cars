#pragma once
#include <iostream>
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public ElectricCar, public PetrolCar {
public:
    HybridCar(std::unique_ptr<PetrolEngine>, std::unique_ptr<ElectricEngine>);
    ~HybridCar();
    void refill() override;
};
