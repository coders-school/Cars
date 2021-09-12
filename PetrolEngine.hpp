#pragma once
#include "Engine.hpp"

class PetrolEngine : public Engine {
public:
    PetrolEngine(Engine::HorsePower power, float capacity, int gears);
    void changeGear(int gear);

private:
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
};
