#pragma once
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"

class HybridCar : public PetrolCar, public ElectricCar
{
public:
    // HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    // HybridCar(Engine* petrolEng, Engine* electricEng);
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();
    // void turnLeft();
    // void turnRight();
    // void brake();
    // void accelerate(int speed);
    // void charge();
    // void refuel();
    void refill() override;
    void changeEngine(ElectricEngine* engine);
    void changeEngine(PetrolEngine* engine);


private:
    // PetrolEngine* petrolEngine_;
    // ElectricEngine* electricEngine_;
};
