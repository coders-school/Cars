#pragma once

class ElectricEngine
{
protected:
    int power_;             // in HP
    int batteryCapacity_;   // in Ah
public:
    ElectricEngine(int power, int batteryCapacity);

};

