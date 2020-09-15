#pragma once
#include "ElectricEngine.hpp"
#include "Vehicle.hpp"

class ElectricCar : virtual public Vehicle {
    ElectricEngine* engine_;
    void charge();

   public:
    explicit ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void restore() override;
};
