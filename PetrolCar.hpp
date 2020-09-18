#pragma once

#include <memory>

#include "Car.hpp"
#include "PetrolEngine.hpp"

#include "Exceptions.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar();

    void restore() override;
    void changeEngine(std::unique_ptr<PetrolEngine> engine);

protected:
    std::unique_ptr<PetrolEngine>  engine_;
    void refuel();
};
