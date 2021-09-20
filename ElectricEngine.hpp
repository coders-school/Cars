#pragma once
#include "Engine.hpp"
#include "Chargeable.hpp"

class ElectricEngine : public Engine, public Chargeable {
public:
    ElectricEngine(int power, int batteryCapacity);
    ~ElectricEngine() override;

    void charge() override;

protected:
    int batteryCapacity_;  // in Ah
};
