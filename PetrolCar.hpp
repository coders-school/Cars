#pragma once
#include <memory>
#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar();
    void refuel();
    void restore() override;
    void changeGear(GearBox gear);

protected:
    std::unique_ptr<PetrolEngine> petrolEngine_;
};
