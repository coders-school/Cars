#pragma once

class ElectricEngine
{
public:
    ElectricEngine(int power, int batteryCapacity);
    int getPower() const;
    int getBatteryCapacity() const;

    void setPower(int);
    void setBaterryCapacity(int);

private:
    int power_;             // in HP 
    int batteryCapacity_;   // in Ah
};

