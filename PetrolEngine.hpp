#pragma once

class PetrolEngine
{
public:
    PetrolEngine(unsigned power, float capacity, int gears);
    unsigned getEnginePower() const;
    void changeGear(int gear);
    int getCurrentGear() const;

private:
    bool isGearInRange(int gear);
    bool doesGearChangeImmediatelyFromForwardToReverse(int gear);
    bool doesGearChangeImmediatelyFromReverseToForward(int gear);
    void checkIfChangingIsAllowed(int gear);
    
    unsigned power_;    // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
