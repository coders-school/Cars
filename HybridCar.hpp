#pragma once
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    virtual ~HybridCar();
    void refill() override;

private:
    void charge();
    void refuel();
    PetrolEngine* petrolEngine_;
    ElectricEngine* electricEngine_;
};
