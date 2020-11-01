#pragma once

class ElectricEngine {
public:
    ElectricEngine(int power, int maxBatteryCapacity, int currentBatteryCapacity);

    int power_;                   // in HP
    int maxBatteryCapacity_;      // in Ah
    int currentBatteryCapacity_;  //in Ah
};
