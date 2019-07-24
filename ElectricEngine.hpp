#pragma once

class ElectricEngine
{
public:
    ElectricEngine(int power, int batteryCapacity);
    ~ElectricEngine();

    int getGear();
    bool isGearValid(int& gear);

    int power_;             // in HP 
    int batteryCapacity_;   // in Ah
    int gears_;
    int currentGear_;
};

