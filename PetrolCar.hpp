#pragma once

#include "Car.hpp"
#include "PetrolEngine.hpp"

constexpr int REVERSE = -1;

class PetrolCar : public virtual Car
{
public:
    PetrolCar(PetrolEngine* engine);
    virtual ~PetrolCar();
    
    size_t getFuelLevel();
    void setEngine(PetrolEngine*);
    void restore() override;
    void changeGear(int gear) override;

private:
    size_t fuelLevel_ = MIN_CAPACITY;
    PetrolEngine* engine_;

    void refuel();
};
