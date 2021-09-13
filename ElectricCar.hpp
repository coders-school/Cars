#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public virtual Car {
   public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();

    void restore() override;

    void changeEngine(ElectricEngine* ee);

   private:
    void charge();
    ElectricEngine* engine_;
};
