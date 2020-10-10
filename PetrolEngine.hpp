#pragma once

class PetrolEngine {
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);

    int getGears() const;
    int getCurrentGear() const;

    int power_;       // in HP
    float capacity_;  // in ccm

private:
    int gears_;
    int currentGear_;
};
