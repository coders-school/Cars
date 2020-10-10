#pragma once

#include <memory>

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
private:
    std::unique_ptr<Engine> engine_;
    void refuel();
public:
    PetrolCar(std::unique_ptr<Engine> engine);
    ~PetrolCar();
    void restore() override;
};
