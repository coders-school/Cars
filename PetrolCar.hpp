#pragma once

#include "PetrolEngine.hpp"
#include "Vehicle.hpp"
class PetrolCar : virtual public Vehicle {
    PetrolEngine* engine_;
    void refuel();

   public:
    explicit PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void restore() override;
};
