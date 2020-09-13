#pragma once

class ElectricEngine
{
public:
    ElectricEngine(int power, int batteryCapacity);

    int getPower() const { return power_; }
    int getBatteryCapacity() const { return batteryCapacity_; }
private:
    int power_;             // in HP 
    int batteryCapacity_;   // in Ah
};

