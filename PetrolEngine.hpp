#pragma once

class PetrolEngine {
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);

    int getGear() const;
    int getCurrentGear() const;
    float getCapacity() const;
    int power_;       // in HP
   // float capacity_;  // in ccm
private:
    int gears_;
    int currentGear_;
    float capacity_;  // in ccm
};
