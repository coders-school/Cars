#pragma once

class PetrolEngine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    ~PetrolEngine();

    void changeGear(int gear);
    int getGears();
    int getPower();

private:
    int power_;
    float capacity_;
    int gears_;
    int currentGear_;
};
