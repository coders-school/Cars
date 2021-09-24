#pragma once

#include "Engine.hpp"

class ElectricEngine : public Engine
{
public:
    ElectricEngine(int power, float capacity);
    ~ElectricEngine() override;
    void fillUp() override;
    int getMaxSpeed() override;
    int getMaxReverseSpeed() override;
};

