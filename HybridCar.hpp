#pragma once

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public ElectricCar, public PetrolCar {
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);

    // Override from Car
    ~HybridCar() override;
    void restore() override;
    void changeEngine(Engine* engine) override;
};

