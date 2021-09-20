#pragma once
#include "Car.hpp"
#include "Refuelable.hpp"
#include "Gearable.hpp"
#include <memory>

class PetrolEngine;

class PetrolCar : virtual public Car, public Refuelable, public Gearable {
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar() override;

    void refuel() override;
    void changeGear(int gear) override;
    
protected:
    std::unique_ptr<PetrolEngine> engine_;
};
