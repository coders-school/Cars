#pragma once
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();
    virtual void restore() override;

    virtual void printInfoEngine() const override;
    void changeEngine(std::unique_ptr<ElectricEngine> electricEngine, std::unique_ptr<PetrolEngine> petrolEngine);
};