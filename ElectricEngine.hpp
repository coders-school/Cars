#pragma once

class ElectricEngine {
public:
    ElectricEngine(int power, int batteryCapacity);
    ~ElectricEngine();

    int getBatteryCapacity() const;
    int power_;  // in HP

private:
    int batteryCapacity_;  // in Ah
};
