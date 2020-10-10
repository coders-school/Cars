#pragma once

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public PetrolCar, public ElectricCar
{
public:
    HybridCar(std::shared_ptr<PetrolEngine> petrolEngine, std::shared_ptr<ElectricEngine> electricEngine);
    virtual ~HybridCar();

    void restore() override;
    void changeGear(int gear) override;
    void setEngine(std::shared_ptr<PetrolEngine>);
    void setEngine(std::shared_ptr<ElectricEngine>);
    void setEngine(std::shared_ptr<PetrolEngine>, std::shared_ptr<ElectricEngine>);
};
