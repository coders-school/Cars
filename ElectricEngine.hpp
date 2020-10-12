#pragma once
//#include "Engine.hpp"


//class ElectricEngine : public Engine {
class ElectricEngine {
public:
    ElectricEngine(int power, int batteryCapacity);
    ~ElectricEngine();

    int getBatteryCapacity() const;
    int getPower() const;

private:
    int power_;  // in HP
    int batteryCapacity_;  // in Ah
};
