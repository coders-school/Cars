#pragma once

#include "ICar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class HybridCar :  public ICar
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();
    void turnLeft() const override;
    void turnRight() const override;
    void brake() const override;
    void accelerate(int speed) const override;
    void charge();
    void refuel();

    PetrolEngine* petrolEngine_;
    ElectricEngine* electricEngine_;
};

