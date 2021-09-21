#pragma once
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

#include <iostream>

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, ElectricEngine* electricEng);
    ~HybridCar() ;
    void refill() override;
    void changeEngine(std::unique_ptr<PetrolEngine> petrolEngineNew, ElectricEngine* electroEngineNew);
    // void changeEngine(ElectricEngine* electroEngineNew);
private:
    std::unique_ptr<PetrolEngine> petrolEngine_;
    ElectricEngine* electricEngine_;
};
