#pragma once

#include <memory>

#include "ElectricCar.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include "ElectricEngine.hpp"

class HybridCar : public ElectricCar
                , public PetrolCar
{
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng,
              std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();

    void restore() override;
    void changePetrolEngine(std::unique_ptr<PetrolEngine>  engine);
    void changeElectricEngine(std::unique_ptr<ElectricEngine>  engine);

private:
    std::unique_ptr<PetrolEngine> petrolEngine_;
    std::unique_ptr<ElectricEngine> electricEngine_;
};
