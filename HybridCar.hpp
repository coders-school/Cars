#pragma once

#include <memory>

#include "PetrolCar.hpp"
#include "ElectricCar.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(std::unique_ptr<Engine> petrolEng, std::unique_ptr<Engine> secondEng);
    ~HybridCar();
    void restore() override;
};
