#pragma once
#include "InvalidsError.hpp"

class PetrolEngine {
public:
    PetrolEngine(int power, float capacity, int gears);
    ~PetrolEngine();
    void changeGear(int gear);
    void showCurrentGear();
    int getCurrentGear();
    void getInfoEngine();

private:
    int power_;       // in HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
};