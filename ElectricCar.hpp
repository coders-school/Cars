#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public virtual Car {
public:
    ElectricCar(ElectricEngine* engine);
    virtual ~ElectricCar();

    size_t getChargeLevel();
    void setEngine(ElectricEngine*);
    void restore() override;
    void changeGear(int gear) override;

private:
    size_t chargeLevel_ = MIN_CAPACITY;
    ElectricEngine* engine_;
    
    void charge();
};
