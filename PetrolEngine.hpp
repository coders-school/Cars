#pragma once
#include "Engine.hpp"

class PetrolEngine : public Engine {
public:
    struct CubicCentimetre {
        explicit CubicCentimetre(float capacity)
            : val(capacity) {}
        float val;
    };

    struct Gear {
        explicit Gear(int gear)
            : val(gear) {}
        int val;
        bool operator==(const Gear& other) const;
        bool operator>(const Gear& other) const;
        bool operator<(const Gear& other) const;
    };

    PetrolEngine(Engine::HorsePower power, CubicCentimetre capacity, Gear maxGear);
    void changeGear(Gear gear);

private:
    CubicCentimetre capacity_;
    Gear maxGear_;
    Gear currentGear_;
};
