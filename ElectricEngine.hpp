#pragma once

class ElectricEngine
{
    int power_;             // in HP 
    int batteryCapacity_;   // in Ah

public:
    ElectricEngine(int power, int batteryCapacity);

    int getElectricPower() const;

    int getBatteryCapacity() const;
};

