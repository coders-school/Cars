#pragma once
#include <iostream>
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
private:
    std::shared_ptr<PetrolEngine> petrolEngine;
    std::shared_ptr<ElectricEngine> electricEngine_;

public:
    HybridCar(std::shared_ptr<PetrolEngine> petrolEng, std::shared_ptr<ElectricEngine> electricEng);
    ~HybridCar();
    void refill() override;
};
