#pragma once
#include "Engine.hpp"

class PetrolEngine : public Engine {
public:
    struct CubicCentimetre {
        explicit CubicCentimetre(float ccm)
            : ccm_(ccm) {}
        float ccm_;
    };

    PetrolEngine(Engine::HorsePower power, CubicCentimetre capacity, int gears);
    void changeGear(int gear);

private:
    CubicCentimetre capacity_;
    int gears_;
    int currentGear_;
};
