#pragma once
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

#include <memory>

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(std::shared_ptr<PetrolEngine> petrolEng,
              std::shared_ptr<ElectricEngine> electricEng);
    ~HybridCar();

    std::shared_ptr<PetrolEngine> petrolEngine_;
    std::shared_ptr<ElectricEngine> electricEngine_;
    void restore() override;  // Car
};
