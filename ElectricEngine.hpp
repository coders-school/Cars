#pragma once

class ElectricEngine {
public:
    ElectricEngine(int power, int batteryCapacity);
    void getInfoEngine();

private:
    int power_;            // in HP
    int batteryCapacity_;  // in Ah
};