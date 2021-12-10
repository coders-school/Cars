#pragma once

#include <memory>

#include "Car.hpp"
#include "PetrolEngine.hpp"


class PetrolCar : virtual public Car {
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar();
    void refill() override;

protected:
    void refuel();
    std::unique_ptr<PetrolEngine> engine_;
};
