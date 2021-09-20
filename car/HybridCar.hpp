#pragma once

#include <memory>

#include "car/ElectricCar.hpp"
#include "car/PetrolCar.hpp"
#include "engine/PetrolEngine.hpp"
#include "engine/ElectricEngine.hpp"

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
