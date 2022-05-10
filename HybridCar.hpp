#pragma once
#include <memory>
#include "ElectricEngine.hpp"
#include "ElectricCar.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public ElectricCar, public PetrolCar
{
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();
    void refill() override;
    void changeEngine(std::unique_ptr<PetrolEngine> engine) override;
    void changeEngine(std::unique_ptr<ElectricEngine> engine) override;
};