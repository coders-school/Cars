#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public Car
{
public:
    HybridCar(PetrolEngine* petrolEngine, ElectricEngine* electricEngine);
    ~HybridCar();
    void accelerate(int speed) override;
    void charge();
    void refuel();

    PetrolEngine* petrolEngine_;
    ElectricEngine* electricEngine_;
};

