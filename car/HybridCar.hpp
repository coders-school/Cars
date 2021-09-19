#pragma once

#include <memory>

#include "ElectricCar.hpp"
#include "PetrolCar.hpp"
#include "../engine/PetrolEngine.hpp"
#include "../engine/ElectricEngine.hpp"

class HybridCar : public ElectricCar
                , public PetrolCar
{
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng,
              std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();

    void restore() override;

private:
    std::unique_ptr<PetrolEngine> petrolEngine_;
    std::unique_ptr<ElectricEngine> electricEngine_;
};
