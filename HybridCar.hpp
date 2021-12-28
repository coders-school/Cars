#pragma once
#include <iostream>
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public ElectricCar, public PetrolCar {
public:
    HybridCar(PetrolEngine* petrolEngine, ElectricEngine* electricEngine);
    ~HybridCar();
    void refill() override;
};
