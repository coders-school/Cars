#pragma once

class ElectricEngine
{
public:
    ElectricEngine(int power, int batteryCapacity);

    ElectricEngine& operator=(ElectricEngine& other){
        power_ = other.power_;
        batteryCapacity_ = other.batteryCapacity_;
        return *this;
    }

private:
    int power_;             // in HP 
    int batteryCapacity_;   // in Ah
};

