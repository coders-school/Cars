#pragma once

#include<memory>

#include "Car.hpp"
#include "PetrolEngine.hpp"

constexpr int REVERSE = -1;

class PetrolCar : public virtual Car
{
public:
    PetrolCar(std::shared_ptr<PetrolEngine> engine);
    virtual ~PetrolCar();
    
    size_t getFuelLevel();
    void setEngine(std::shared_ptr<PetrolEngine>);
    void restore() override;
    void changeGear(int gear) override;

private:
    size_t fuelLevel_ = MIN_CAPACITY;
    std::shared_ptr<PetrolEngine> engine_;

    void refuel();
};
