#pragma once
#include <memory>
#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar();
    void restore() override;
    void changePetrolEngine(std::unique_ptr<PetrolEngine> newEngine);
    void changeGear(int gear);

protected:
    void refuel();
    std::unique_ptr<PetrolEngine> petrolEngine_;
};
