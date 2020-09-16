#pragma once

class ElectricEngine {
public:
    ElectricEngine(int power, int batteryCapacity);

private:
    int power_;
    int batteryCapacity_;  // in Ah
};
