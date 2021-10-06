#pragma once
#include <iostream>

class ElectricEngine {
public:
    ElectricEngine(int power, int batteryCapacity);
    ~ElectricEngine();

private:
    int power_;             // in HP 
    int batteryCapacity_;   // in Ah
};
