#pragma once
#include "Engine.hpp"

class PetrolEngine : public Engine {
public:
    struct CubicCentimetre {
        explicit constexpr CubicCentimetre(float capacity)
            : val(capacity) {}
        float val;
    };

    struct Gear {
        explicit constexpr Gear(int gear)
            : val(gear) {}
        int val;
        bool operator==(const Gear& other) const;
        bool operator>(const Gear& other) const;
        bool operator<(const Gear& other) const;
    };

    PetrolEngine(const Engine::HorsePower& power, const CubicCentimetre& capacity, const Gear& maxGear);
    void changeGear(const Gear& gear);

private:
    CubicCentimetre capacity_;
    Gear maxGear_;
    Gear currentGear_;
};
