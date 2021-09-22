#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "Engine.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public Car
{
public:
    HybridCar(Engine* electricEng, Engine* petrolEng);
    ~HybridCar();
    void accelerate(int speed);

private:
    Engine* petrolEngine_;
};

