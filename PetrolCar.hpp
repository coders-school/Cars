#pragma once

#include "PetrolEngine.hpp"
#include "Car.hpp"

#include <memory>

class PetrolCar : virtual public Car
{
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar();
    void restore() override;
    void changeGear(int gear);
    void changeEngine(std::unique_ptr<PetrolEngine> engine);

    std::unique_ptr<PetrolEngine> engine_;
private:
    void refuel();
};

