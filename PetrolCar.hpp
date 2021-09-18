
#pragma once
#include <memory>
#include "Car.hpp"
#include "PetrolEngine.hpp"


class PetrolCar : virtual public Car {
private:
    std::shared_ptr<PetrolEngine> engine_;
public:
    PetrolCar(std::shared_ptr<PetrolEngine> engine);
    ~PetrolCar();
    void refuel();
    void changeGear(int gear);
};
