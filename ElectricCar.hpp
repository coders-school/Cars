#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public virtual Car {
public:
    ElectricCar(ElectricEngine* engine);
    virtual ~ElectricCar();

    size_t getChargeLevel();
    virtual void setEngine(PetrolEngine*) override;                  // overloaded (not used)
    virtual void setEngine(ElectricEngine*) override;
    virtual void setEngine(PetrolEngine*, ElectricEngine*) override; // overloaded (not used)
    void restore() override;
    void changeGear(int gear) override;

private:
    size_t chargeLevel_ = MIN_CAPACITY;
    ElectricEngine* engine_;
    
    void charge();
};
