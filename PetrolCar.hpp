#pragma once

#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : virtual public Car //słówko virtual sprawia że HybridCar nie będzie dziedziczył po PetrolCar
                                    // i ElectricCar klasę Car, tylko stricte z klasy Car. (Ma tylko jedną "sztukę" tego Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void restore() override;

    PetrolEngine* engine_;
private:
    void refuel();
};

