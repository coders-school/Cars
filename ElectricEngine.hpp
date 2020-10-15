#pragma once

class ElectricEngine {
public:
    ElectricEngine(int power, int batteryCapacity);
    ~ElectricEngine();

    int getBatteryCapacity() const;
    int getPower() const;

private:
    int power_;            // in HP
    int batteryCapacity_;  // in Ah
};
