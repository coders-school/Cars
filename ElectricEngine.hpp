#pragma once

class ElectricEngine {
public:
    ElectricEngine(int power, int batteryCapacity, int currentCapacity);
    int GetCurrentCapacity() { return currentCapacity_; }
    int GetBatteryCapacity() { return batteryCapacity_; }
    void SetCurrentCapacity(int capacity) { currentCapacity_ = capacity; }

protected:
    int power_;
    int batteryCapacity_;  // in Ah
    int currentCapacity_;  // in Ah
};
