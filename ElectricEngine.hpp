#pragma once

class ElectricEngine
{
public:
    ElectricEngine(int power, int batteryCapacity);
    ~ElectricEngine();
    int getPower();
    int getBatteryCapacity();
private:
    int power_;             // in HP 
    int batteryCapacity_;   // in Ah
};

