#pragma once

class ElectricEngine {
public:
    ElectricEngine(int power, int batteryCapacity);
    ~ElectricEngine();
    void setBatteryCapacity(int batteryCapacity) { batteryCapacity_ = batteryCapacity; };
    int getBatteryCapacity() const { return batteryCapacity_; };
    void setPower(int power) { power_ = power; };
    int getPower() const { return power_; };

private:
    int power_;            //in HP
    int batteryCapacity_;  // in Ah
};