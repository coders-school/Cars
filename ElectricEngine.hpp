#pragma once
#include "IEngine.hpp"

class ElectricEngine : IEngine
{
public:
    ElectricEngine(int power, int batteryCapacity);
    ~ElectricEngine();
    void start() const override;
    void stop() const override;

    int power_;             // in HP 
    int batteryCapacity_;   // in Ah
};

