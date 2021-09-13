#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public virtual Car {
   public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();

    void restore() override;

    ElectricEngine* engine_;

   private:
    void charge();
};
