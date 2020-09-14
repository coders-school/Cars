#pragma once

#include "Engine.hpp"

class PetrolEngine : public Engine {
public:
    PetrolEngine(uint16_t power, uint16_t capacity, uint8_t gears);
    uint16_t getCapacity() const { return capacity_; }
    uint8_t getGears() const { return gears_; }
    int getCurrentGear() const { return currentGear_; }
    void setCurrentGear(int gear);

private:
    uint16_t capacity_{};  // in ccm
    uint8_t gears_{};
    int currentGear_{};
};
