#pragma once

#include<memory>

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public virtual Car {
public:
    ElectricCar(std::shared_ptr<ElectricEngine> engine);
    virtual ~ElectricCar();

    size_t getChargeLevel();
    void setEngine(std::shared_ptr<ElectricEngine>);
    void restore() override;
    void changeGear(int gear) override;

private:
    size_t chargeLevel_ = MIN_CAPACITY;
    std::shared_ptr<ElectricEngine> engine_;
    
    void charge();
};
