#pragma once

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(PetrolEngine* petrolEngine, ElectricEngine* electricEngine);

    //Override from Car
    ~HybridCar() override;
    void restore() override;
    uint16_t getEnginePower() override;
    void carInfo() override;
    void changeEngine(Engine* engine) override;
    void setSumPower(uint16_t powerOfPetrolEngine, uint16_t powerOfElectricEngine);
    uint16_t getSumPower() const { return sumPower_; }

private:
    uint16_t sumPower_{};
};
