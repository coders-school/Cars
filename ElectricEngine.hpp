#pragma once
#include "Engine.hpp"

class ElectricEngine : public Engine {
public:
    struct AmpereHour {
        explicit AmpereHour(int ah)
            : ah_(ah) {}
        int ah_;
    };

    ElectricEngine(Engine::HorsePower power, AmpereHour batteryCapacity);

private:
    AmpereHour batteryCapacity_;
};
