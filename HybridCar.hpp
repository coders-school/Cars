#pragma once
#include <iostream>

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();
    void refill() override;
    void changeEngine(std::unique_ptr<PetrolEngine> petrolEngineNew) override;
    void changeEngine(std::unique_ptr<ElectricEngine> electroEngineNew) override;

private:
    std::unique_ptr<PetrolEngine> petrolEngine_;
    std::unique_ptr<ElectricEngine> electricEngine_;
};
