#pragma once

#include "Engine.hpp"

class PetrolEngine : public Engine {
private:
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;

public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);
    ~PetrolEngine() override {}

};
