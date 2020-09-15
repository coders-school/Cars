#pragma once
#include "ElectricEngine.hpp"
#include "Vehicle.hpp"

class ElectricCar : virtual public Vehicle {
    ElectricEngine* engine_;
    AmpereHour currentBatteryLevel_;
    void charge();

   public:
    explicit ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void restore() override;
    AmpereHour getBatteryLevel() const { return currentBatteryLevel_; };
    const ElectricEngine& getEngine() const { return *engine_; }
};
