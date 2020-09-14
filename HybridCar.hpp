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
    virtual void setEngine(PetrolEngine*) override;     // overloaded (not used)
    virtual void setEngine(ElectricEngine*) override;   // overloaded (not used)
    virtual void setEngine(PetrolEngine*, ElectricEngine*) override;

private:
    PetrolEngine* petrolEngine_;
    ElectricEngine* electricEngine_;
};
