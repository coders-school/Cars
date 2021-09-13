#pragma once
#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : public virtual Car {
   public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();

    void restore() override;

    void changeEngine(PetrolEngine* pe);

   private:
    void refuel();
    PetrolEngine* engine_;
};
