#pragma once
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

#include "ElectricCar.hpp"
#include "PetrolCar.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();

    PetrolEngine* petrolEngine_;
    ElectricEngine* electricEngine_;
    void restore() override;  // Car
};
