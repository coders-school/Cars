#pragma once

#include <memory>

#include "car/Car.hpp"
#include "engine/PetrolEngine.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar();

    void refuel();
    void changeGear(int gear);
    void restore() override;
    int getCurrentGear();
    void changeEngine(std::unique_ptr<PetrolEngine>  engine);

private:
    std::unique_ptr<PetrolEngine> engine_;
};
