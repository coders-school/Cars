#pragma once
#include "Engine.hpp"

class ElectricEngine : public Engine {
public:
    struct AmpereHour {
        explicit constexpr AmpereHour(int batteryCapacity)
            : val(batteryCapacity) {}
        int val;
    };

    ElectricEngine(const Engine::HorsePower& power, const AmpereHour& batteryCapacity);

private:
    AmpereHour batteryCapacity_;
};
