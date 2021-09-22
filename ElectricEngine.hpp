#pragma once
#include "Engine.hpp"
#include "ElectricCapacity.hpp"

class ElectricEngine : public Engine {
public:
    ElectricEngine(Power power, ElectricCapacity batteryCapacity);
    ~ElectricEngine() override;

protected:
    ElectricCapacity batteryCapacity_;  // in Ah
};
