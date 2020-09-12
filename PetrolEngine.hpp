#pragma once

#include <cstddef>

#include "Engine.hpp"

class PetrolEngine : public Engine {
public:
    PetrolEngine(uint16_t power, size_t capacity, uint8_t gears);
    size_t getCapacity() { return capacity_; }
    uint8_t getGears() { return gears_; }
    int getCurrentGear() { return currentGear_; }
    void setCurrentGear(int gear);

private:
    size_t capacity_{};  // in ccm
    uint8_t gears_{};
    int currentGear_{};
};
