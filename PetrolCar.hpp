#pragma once

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : public virtual Car
{
public:
    PetrolCar(PetrolEngine* engine);
    virtual ~PetrolCar();
    
    size_t getFuelLevel();
    virtual void setEngine(PetrolEngine*) override;
    virtual void setEngine(ElectricEngine*) override;                // overloaded (not used)
    virtual void setEngine(PetrolEngine*, ElectricEngine*) override; // overloaded (not used)
    void restore() override;
    void changeGear(int gear) override;

private:
    size_t fuelLevel_ = MIN_CAPACITY;
    PetrolEngine* engine_;

    void refuel();
};
