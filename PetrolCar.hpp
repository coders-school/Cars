
#pragma once
#include <memory>
#include "Car.hpp"
#include "PetrolEngine.hpp"
#include "Car.hpp"


class PetrolCar : virtual public Car {
private:
    std::shared_ptr<PetrolEngine> engine_;
public:
    PetrolCar(std::shared_ptr<PetrolEngine> engine);
    ~PetrolCar();

    void changeGear(int newGear);
    void changeEngine(std::shared_ptr<PetrolEngine>  pe);
    void refill() override;

private:
    void refuel();
    
};
