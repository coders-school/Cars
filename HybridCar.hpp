#pragma once

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public PetrolCar, public ElectricCar
{
public:
    HybridCar(PetrolEngine* petrolEngine, ElectricEngine* electricEngine);
    virtual ~HybridCar();

    void restore() override;
    void changeGear(int gear) override;
    void setEngine(PetrolEngine*);
    void setEngine(ElectricEngine*);
    void setEngine(PetrolEngine*, ElectricEngine*);
};
