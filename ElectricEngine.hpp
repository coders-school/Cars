#pragma once

class ElectricEngine
{
public:
    ElectricEngine(int power, int batteryCapacity);
    ~ElectricEngine();
    
    int getPower();

private:
    int power_;
    int batteryCapacity_;
};
