#pragma once

class PetrolEngine
{
private:

    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;

public:
    PetrolEngine(int power=80, float capacity=1100, int gears=5);
    void changeGear(int gear);
    int returnGear();

};
