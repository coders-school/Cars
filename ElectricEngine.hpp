#pragma once
#include "Engine.hpp"

class ElectricEngine : public Engine {
public:
    struct AmpereHour {
        explicit AmpereHour(int batteryCapacity)
            : val(batteryCapacity) {}
        int val;
    };

    ElectricEngine(Engine::HorsePower power, AmpereHour batteryCapacity);

private:
    AmpereHour batteryCapacity_;
};
