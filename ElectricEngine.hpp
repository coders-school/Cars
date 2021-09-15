#pragma once

class ElectricEngine
{
public:
    ElectricEngine(int power, int batteryCapacity);
    int getPower() const;
    int getBatteryCapacity() const;

    void setPower();
    void setBaterryCapacity();
    
private:
    int power_;             // in HP 
    int batteryCapacity_;   // in Ah
};

