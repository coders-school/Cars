#pragma once

#include "ICar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include <memory>

class HybridCar :  public ICar
{
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();
    void turnLeft() const override;
    void turnRight() const override;
    void brake() const override;
    void accelerate(Speed speed) const override;
    void charge();
    void refuel();

private:
    std::unique_ptr<PetrolEngine> petrolEngine_ = nullptr;
    std::unique_ptr<ElectricEngine> electricEngine_ = nullptr;
};

