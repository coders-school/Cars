#pragma once

#include "PetrolEngine.hpp"
#include "Vehicle.hpp"

class Litre {
    public:
    float value_;
    explicit Litre(float value) : value_(value) {}
};
class PetrolCar : virtual public Vehicle {
    PetrolEngine* engine_;
    Litre maxTankCapacity_;
    Litre currentTankCapacity_;

    void refuel();

   public:
    explicit PetrolCar(PetrolEngine* engine, Litre tankCapacity);
    ~PetrolCar();
    void restore() override;
    Litre getCurrentTankCapacity() const { return currentTankCapacity_; }
    Litre getMaxTankCapacity() const { return maxTankCapacity_; }
};
