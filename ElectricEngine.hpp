#pragma once

class ElectricEngine
{
private:
    int power_;             // in HP 
    int batteryCapacity_;   // in Ah
public:
    ElectricEngine(int power, int batteryCapacity);
};

