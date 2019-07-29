#pragma once

class PetrolEngine
{
    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;

public:
    PetrolEngine(int power, float capacity, int gears);
    
    int getPower() const;

    int getCapacity() const;

    int getMaxGear() const;

    int getCurrentGear() const;

    void changeGear(int gear);

    
};
