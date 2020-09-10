#pragma once
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"

class HybridCar :public PetrolCar, public ElectricCar {
   public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();
    void turnLeft() override;
    void turnRight() override;
    void brake() override;
    void accelerate(int speed) override;

};
