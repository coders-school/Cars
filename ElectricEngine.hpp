#pragma once
#include "Engine.hpp"

class ElectricEngine : public Engine
{
public:
    ElectricEngine(int power, int batteryCapacity);

    ElectricEngine(ElectricEngine const &) = default;
    ElectricEngine(ElectricEngine &&) = default;

    ElectricEngine & operator=(ElectricEngine const &) = default;
    ElectricEngine & operator=(ElectricEngine &&) = default;

    ~ElectricEngine() override;
    
    int getBatteryCapacity() const { return batteryCapacity_; }

    friend std::ostream & operator<<(std::ostream & out, ElectricEngine const & engine);

private:
    int batteryCapacity_;   // in Ah
};

