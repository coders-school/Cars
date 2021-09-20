#pragma once

class ElectricEngine {
public:
    ElectricEngine(int power, int batteryCapacity);

    int getPower();
    int getBatteryCapacity();
    void setPower(int);
    void setBatteryCapacity(int);

private:
    int power_;            // in HP
    int batteryCapacity_;  // in Ah
};
