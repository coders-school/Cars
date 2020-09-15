#pragma once
#include "ElectricEngine.hpp"
#include "Vehicle.hpp"

class ElectricCar : virtual public Vehicle {
    ElectricEngine* engine_;
    void charge();

   public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void restore() override;
};
