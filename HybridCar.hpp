#pragma once
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include <iostream>
#include <memory>

class HybridCar : public PetrolCar, public ElectricCar
{
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();
    void refill() override;

private:
    std::unique_ptr<PetrolCar> petrol_;
    std::unique_ptr<ElectricCar> electric_;
};
