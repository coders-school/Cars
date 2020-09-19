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
    int getPetrolEnginePower() { return engine_->getPower(); }
    float getPetrolEngineCapacity() { return engine_->getCapacity(); }

protected:
    std::unique_ptr<PetrolEngine> engine_;
    void refuel();
};
