#pragma once

class PetrolEngine
{
public:
    PetrolEngine(unsigned power, float capacity, int gears);
    void changeGear(int gear);
    unsigned getEnginePower() const;

private:
    unsigned power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
