#pragma once
#include <iostream>

class ElectricEngine
{
public:
    ElectricEngine(int power, int batteryCapacity);
    
    void setPower(int power)
    {
        if (power < 0) {
            std::cerr << "Power cannot be negative" << std::endl;
            return;
        }
        power_ = power;
    }
    int getPower() const
    {
        return power_;
    }

private:
    int power_;             // in HP 
    int batteryCapacity_;   // in Ah
};

