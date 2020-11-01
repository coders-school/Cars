#pragma once
#include <memory>
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();
    void restore() override;
    void changeEngine(std::unique_ptr<ElectricEngine> newElectricEngine, std::unique_ptr<PetrolEngine> newPetrolEngine);
};
