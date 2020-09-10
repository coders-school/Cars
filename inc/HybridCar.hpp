#pragma once

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public ElectricCar, public PetrolCar {
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();

    //override from Car
    void restore() override;
    void changeEngine(Engine* engine) override;
    int getEnginePower() const override { return petrolEngine_->getPower() + electricEngine_->getPower(); }
};
