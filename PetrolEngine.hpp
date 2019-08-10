#pragma once

class PetrolEngine
{
protected:
    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);
};
