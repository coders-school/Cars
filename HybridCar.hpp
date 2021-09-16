#pragma once
#include <iostream>
#include <memory>
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    virtual ~HybridCar();
    void refill() override;
    void changeEngine(std::unique_ptr<PetrolEngine> engine) override;
    void changeEngine(std::unique_ptr<ElectricEngine> engine) override;
};
