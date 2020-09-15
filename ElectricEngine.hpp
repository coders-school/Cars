#pragma once

#include "HorsePower.hpp"
class ElectricEngine {
    HorsePower power_;     //in HP
    int batteryCapacity_;  // in Ah

   public:
    ElectricEngine(HorsePower power, int batteryCapacity);
    ~ElectricEngine();
};
