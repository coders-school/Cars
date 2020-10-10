#pragma once

#include "PetrolCar.hpp"
#include "ElectricCar.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* secondEng);
    ~HybridCar();
    void restore() override;
};
