#pragma once
#include <memory>
#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    virtual ~PetrolCar();
    void refill() override;
    void changeEngine(std::unique_ptr<PetrolEngine> engine) override;
    PetrolEngine* getEngine();

private:
    void refuel();
    std::unique_ptr<PetrolEngine> engine_;
};
