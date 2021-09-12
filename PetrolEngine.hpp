#pragma once
#include "Engine.hpp"

class PetrolEngine : public Engine {
public:
    struct CubicCentimetre {
        explicit CubicCentimetre(float ccm)
            : ccm_(ccm) {}
        float ccm_;
    };

    struct Gear {
        explicit Gear(int gear)
            : gear_(gear) {}
        int gear_;
        bool operator==(const Gear& other) const;
    };

    PetrolEngine(Engine::HorsePower power, CubicCentimetre capacity, Gear maxGear);
    void changeGear(Gear gear);

private:
    CubicCentimetre capacity_;
    Gear maxGear_;
    Gear currentGear_;
};
