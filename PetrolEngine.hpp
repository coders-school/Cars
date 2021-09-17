#pragma once

class PetrolEngine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);


    int getPower();
    int getCapacity();
    int getGears();
    int getCurrentGear();

    private: 
    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
